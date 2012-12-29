$NetBSD$

Use proper byteorder functions to decode integer from byte stream.
XXX NetBSD only

--- file.h.orig	2008-01-06 06:20:00.000000000 +0000
+++ file.h
@@ -44,6 +44,32 @@
 #  endif
 #endif
 
+#ifdef __NetBSD__
+
+#define INT_SIZE sizeof(int)
+
+inline int read_little_endian_int(const char* buf) {
+	return le32dec(buf);
+}
+
+inline int read_little_endian_short(const char* buf) {
+	return le16dec(buf);
+}
+
+inline int write_little_endian_int(char* buf, int number) {
+	int c = le32dec(buf);
+	le32enc(buf, number);
+	return c;
+}
+
+inline int write_little_endian_short(char* buf, int number) {
+	int c = le16dec(buf);
+	le16enc(buf, number);
+	return c;
+}
+
+#else // !__NetBSD__
+
 #ifdef WORDS_BIGENDIAN
 
 #define INT_SIZE 4
@@ -103,6 +129,7 @@ inline int write_little_endian_short(cha
 	int c = *(short*)buf; *(short*)buf = number; return c;
 }
 #endif // WORDS_BIGENDIAN
+#endif // __NetBSD__
 
 /*********************************************
 **  FILESEARCH:
