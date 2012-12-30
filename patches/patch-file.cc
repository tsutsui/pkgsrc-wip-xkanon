$NetBSD$

Don't use unaligned word copy that won't work on RISC CPUs.

--- file.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ file.cc
@@ -1719,13 +1719,17 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
+#ifdef __NetBSD__
+		memcpy(ldest, lsrc, 3);
+#else
 #ifdef WORDS_BIGENDIAN
 		ldest[0] = lsrc[0];
 		ldest[1] = lsrc[1];
 		ldest[2] = lsrc[2];
-#else /* LITTLE ENDIAN / intel architecture */
+#else
 		*(int*)ldest = *(int*)lsrc; ldest[3]=0;
 #endif
+#endif
 		lsrc += 3; ldest += 4;
 	}
 	static int ProcessBlockSize(void) {
@@ -1862,6 +1866,9 @@ public:
 		lsrc += 2;
 	}
 	static void Copy1Pixel(const char*& lsrc, char*& ldest) {
+#ifdef __NetBSD__
+		memcpy(ldest, lsrc, 3);
+#else
 #ifdef WORDS_BIGENDIAN
 		ldest[0] = lsrc[0];
 		ldest[1] = lsrc[1];
@@ -1869,6 +1876,7 @@ public:
 #else /* LITTLE ENDIAN / intel architecture */
 		*(int*)ldest = *(int*)lsrc; ldest[3]=0;
 #endif
+#endif
 		lsrc += 3; ldest += 4;
 	}
 	static int ProcessBlockSize(void) {