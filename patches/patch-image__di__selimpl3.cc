$NetBSD$

Explicitly use unsigned char instead of char because
`char' is unsigned by default on arm and powerpc.

--- image_di_selimpl3.cc.orig	2009-08-29 23:12:54.000000000 +0000
+++ image_di_selimpl3.cc
@@ -82,9 +82,9 @@ RegisterSelMacro(70, TLI4(70,71,72,73), 
 			char* s = src_pt + lf * ByPP;
 			char* m = mask_pt + lf;
 			int j; for (j=0; j<dw; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) Copy1Pixel(d ,s);
+					if (mask_char == 0xff) Copy1Pixel(d ,s);
 					else SetMiddleColor(d, s, mask_char);
 				}
 				d+= ByPP; s+=ByPP; if (IsMask) m++;
@@ -101,9 +101,9 @@ RegisterSelMacro(70, TLI4(70,71,72,73), 
 			char* s = src_pt + lf*src.bpl;
 			char* m = mask_pt + lf*src.width;
 			int j; for (j=0; j<dw; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) Copy1Pixel(d,s);
+					if (mask_char == 0xff) Copy1Pixel(d,s);
 					else SetMiddleColor(d, s, mask_char);
 				}
 				d += dest.bpl; s += src.bpl; if (IsMask) m += src.width;
