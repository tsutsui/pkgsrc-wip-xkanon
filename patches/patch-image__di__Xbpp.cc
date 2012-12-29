$NetBSD$

Explicitly use unsigned char instead of char because
`char' is unsigned by default on arm and powerpc.

--- image_di_Xbpp.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ image_di_Xbpp.cc
@@ -181,9 +181,9 @@ void CopyAllWithMask_Xbpp(DI_Image& dest
 		char* mask_line = mask + i*width;
 		char* d = dest_pt; char* s = src_pt;
 		for (j=0; j<width; j++) {
-			char mask_char = *mask_line++;
+			unsigned char mask_char = *mask_line++;
 			if (mask_char) {
-				if (mask_char == -1) {
+				if (mask_char == 0xff) {
 					Copy1Pixel(d,s);
 				} else {
 					SetMiddleColor(d, s, mask_char);
@@ -224,9 +224,9 @@ void CopyRectWithMask_Xbpp(DI_Image& des
 		char* mask_line = mask + (i+src_y)*swidth + src_x;
 		char* d = dest_pt; char* s = src_pt;
 		for (j=0; j<width; j++) {
-			char mask_char = *mask_line++;
+			unsigned char mask_char = *mask_line++;
 			if (mask_char) {
-				if (mask_char == -1) {
+				if (mask_char == 0xff) {
 					Copy1Pixel(d,s);
 				} else {
 					SetMiddleColor(d, s, mask_char);
@@ -538,9 +538,9 @@ void CopyRectWithFadeWithMask_Xbpp(DI_Im
 		char* mask_line = mask + (i+src_y)*swidth + src_x;
 		char* d = dest_pt; char* s = src_pt;
 		for (j=0; j<width; j++) {
-			char mask_char = *mask_line++;
+			unsigned char mask_char = *mask_line++;
 			if (mask_char) {
-				if (mask_char == -1) {
+				if (mask_char == 0xff) {
 					SetMiddleColorWithTable(d, s, table);
 				} else {
 					int tmp; Copy1Pixel((char*)&tmp, d);
