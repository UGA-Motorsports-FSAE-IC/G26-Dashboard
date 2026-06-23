/*
 * rpiSceneBuilderUser.cpp
 *
 *  Created on: May 2, 2025
 *      Author: bhargav
 */

#include "rpiSceneBuilderUser.h"

#include "rpiDisplaySceneBuilder.h"
#include "FreeSans18pt7b.h"
#include "FreeMonoBold24pt7b.h"
#include "FreeSerifBoldItalic18pt7b.h"
#include "gearFont.h"
#include "iconFont.h"
#include "splashimage.h"
#include <cstring>
#include <iterator>

char rpmresult[17] = "";
char tempresult[18] = "";
char speedresult[20] = "";
char gearresult[20] = "8";
char battresult[20] = "";
char tempicon[3] = " ";
char batticon[3] = "\"";
char rpmicon[3] = "#";
char speedicon[3] = "%";
char name[10] = "G-26";
char airtankresult[20] = "";
char airtanklabel[15] = "Air Tank: ";
char sparkcutlabel[20] = "";
char sparkcutstate[20] = "";
char oilpressurelabel[20] = "";
char oilpressureresult[20] = "";
char shiftcountlabel[20] = "Shift Count: ";
char shiftcountresult[20] = "";

DisplayObject* otherobjects[19] = {
		new StringObject(200, 260, 0xFFFF, FREE_MONO_BOLD_24PT7B, NO_CENTER_OBJECT, rpmresult, 1),
		new StringObject(350, 100, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, tempresult, 3),
		new StringObject(350, 60, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, battresult, 6),
		new StringObject(100, 240, 0xFFFF, GEARFONT, CENTER_OBJECT, gearresult, 2),
		new StringObject(395, 130, 0xFFFF, ICONFONT, CENTER_OBJECT, tempicon, 4),
		new StringObject(400, 90, 0xFFFF, ICONFONT, CENTER_OBJECT, batticon, 5),
		new StringObject(375, 185, 0xFFFF, FREE_SANS_18PT7B, LEFTDRAW_OBJECT, speedresult, 7),
		new StringObject(440, 288, 0xFFFF, ICONFONT, LEFTDRAW_OBJECT, rpmicon, 8),
		new OutlineRectObject(190, 250, 260, 55, 0xFFFF, NO_CENTER_OBJECT, 9),
		new StringObject(405, 210, 0xFFFF, ICONFONT, CENTER_OBJECT, speedicon, 10),
		new StringObject(50, 280, 0x003A, FREE_SERIF_BOLD_ITALIC_18PT7B, CENTER_OBJECT, name, 11),
		new StringObject(150, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, airtanklabel, 12),
		new StringObject(40, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, airtankresult, 13),
		new StringObject(160, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, sparkcutlabel, 14),
		new StringObject(40, 20, 0x3f07, FREE_SANS_18PT7B, CENTER_OBJECT, sparkcutstate, 15),
		new StringObject(400, 140, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, oilpressurelabel, 16),
		new StringObject(350, 140, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, oilpressureresult, 17),
		new StringObject(170, 50, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, shiftcountlabel, 18),
		new StringObject(40, 50, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, shiftcountresult, 19)
};

Scene myScene2(otherobjects, 19);


char rpmresult2[17] = "";
char oiltempresult2[18] = "";
char gearresult2[20] = "";
char battresult2[20] = "";
char oiltemp2[15] = "Oil Temp:";
char batt2[15] = "Battery:";
char rpm2[15] = "RPM:";
char gear2[15] = "Gear:";
char* datascreengrid[] = {rpm2, oiltemp2, gear2, batt2};
char* griddata[] = {rpmresult2, oiltempresult2, gearresult2, battresult2};
DisplayObject* dataobjects[12];
Scene myScene3(dataobjects, 12);




char *image = "splash.bin";
DisplayObject* splashobjects[1] = {
		new ImageObject(image, SPLASH_LENGTH, SPLASH_HEIGHT, 240, 160, CENTER_OBJECT, 2)
};
Scene splashScene(splashobjects, 1);




void changebackground(uint16_t color) {
	((FilledRectObject*)otherobjects[10])->updateRect(100, 100, 200, 150, color, CENTER_OBJECT);
}

void setrpmdata(char *rpmvalue) {
	strncpy(rpmresult, "", 10);
	strncat(rpmresult, rpmvalue, 10);
	((StringObject*)otherobjects[0])->updateString(rpmresult, NO_CENTER_OBJECT, 0xFFFF, FREE_MONO_BOLD_24PT7B, 200, 260, 1);
}

void settempdata(char *tempvalue) {
	strncpy(tempresult, "", 10);
	strncat(tempresult, tempvalue, 10);
	((StringObject*)otherobjects[1])->updateString(tempresult, CENTER_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 350, 100, 3);

}

void setgeardata(char *gearvalue) {
	strncpy(gearresult, "", 10);
	strncat(gearresult, gearvalue, 10);
	((StringObject*)otherobjects[3])->updateString(gearresult, CENTER_OBJECT, 0xFFFF, GEARFONT, 100, 240, 2);
}

void setbattdata(char *battvalue) {
	strncpy(battresult, "", 10);
	strncat(battresult, battvalue, 10);
	((StringObject*)otherobjects[2])->updateString(battresult, CENTER_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 350, 60, 6);
}

void setspeeddata(char *speedvalue) {
	strncpy(speedresult, "", 10);
	strncat(speedresult, speedvalue, 10);
	((StringObject*)otherobjects[6])->updateString(speedresult, LEFTDRAW_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 375, 185, 7);
}

void setsparkcut(char *sparkcutvalue, uint16_t color) {
	strncpy(sparkcutstate, "", 10);
	strncat(sparkcutstate, sparkcutvalue, 10);
	((StringObject*)otherobjects[14])->updateString(sparkcutstate, CENTER_OBJECT, color, FREE_SANS_18PT7B, 40, 20, 15);
}


void setairtankdata(char *airtankvalue) {
	strncpy(airtankresult, "", 10);
	strncat(airtankresult, airtankvalue, 10);
	((StringObject*)otherobjects[12])->updateString(airtankresult, CENTER_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 40, 20, 13);
}

void setoilpressuredata(char *oilpressurevalue) {
	strncpy(oilpressureresult, "", 10);
	strncat(oilpressureresult, oilpressurevalue, 10);
	((StringObject*)otherobjects[16])->updateString(oilpressureresult, CENTER_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 350, 140, 17);
}

void setshiftcountdata(char *shiftcountvalue) {
	strncpy(shiftcountresult, "", 10);
	strncat(shiftcountresult, shiftcountvalue, 10);
	((StringObject*)otherobjects[18])->updateString(shiftcountresult, CENTER_OBJECT, 0xFFFF, FREE_SANS_18PT7B, 40, 50, 19);
}


void domainscreen() {
	myScene2.setScene(otherobjects, 19);
	myScene2.drawScene();
}

void dodatascreen() {
	myScene3.setScene(dataobjects, 12);
	myScene3.drawScene();
}

void dosplashscene() {
	splashScene.drawScene();
	splashScene.setScene(splashobjects, 1);
}

void initdatascreen() {
	int length = sizeof(datascreengrid) / sizeof(datascreengrid[0]);
	int x = 0;
	int y = 0;
	for(int i = 0; i < length; i++) {
		dataobjects[i] = new StringObject(x, y, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, datascreengrid[i], i);
		y += 30;
	}
	x = 0;
	y = 0;
	for(int i = 0; i < length; i++) {
		dataobjects[i] = new StringObject(x, y, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, griddata[i], i+length);
		y += 30;
	}
	x = 0;
	y = 0;
	for (int i = 8; i < 12; i++) {
		dataobjects[i] = new OutlineRectObject(x, y, 150, 50, 0xFFFF, NO_CENTER_OBJECT, i);
		y += 30;
	}
	dodatascreen();
}

