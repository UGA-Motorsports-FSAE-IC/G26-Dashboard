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
char oilpressurelabel[20] = "op";
char oilpressureresult[20] = "";
char wslabel[20] = "WS ";
char wsresult[50] = "";

DisplayObject* mainObjects[50] = {
		new OutlineRectObject(190, 250, 260, 55, 0xFFFF, NO_CENTER_OBJECT, 5),
		new StringObject(395, 130, 0xFFFF, ICONFONT, CENTER_OBJECT, tempicon, 5),
		new StringObject(400, 90, 0xFFFF, ICONFONT, CENTER_OBJECT, batticon, 5),
		new StringObject(440, 288, 0xFFFF, ICONFONT, LEFTDRAW_OBJECT, rpmicon, 5),
		new StringObject(405, 210, 0xFFFF, ICONFONT, CENTER_OBJECT, speedicon, 5),
		new StringObject(150, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, airtanklabel, 5),
		new StringObject(400, 145, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, oilpressurelabel, 5),
		new StringObject(440, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, wslabel, 5),
};

DisplayObject* activeObjects[50] = {
		new StringObject(50, 280, 0x003A, FREE_SERIF_BOLD_ITALIC_18PT7B, CENTER_OBJECT, name, 10),
		new StringObject(200, 260, 0xFFFF, FREE_MONO_BOLD_24PT7B, NO_CENTER_OBJECT, rpmresult, 10),
		new StringObject(350, 100, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, tempresult, 10),
		new StringObject(350, 60, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, battresult, 10),
		new StringObject(100, 240, 0xFFFF, GEARFONT, CENTER_OBJECT, gearresult, 10),
		new StringObject(375, 185, 0xFFFF, FREE_SANS_18PT7B, LEFTDRAW_OBJECT, speedresult, 10),
		new StringObject(340, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, wsresult, 10),
		new StringObject(350, 145, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, oilpressureresult, 10),
		new StringObject(40, 20, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, airtankresult, 10)
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

void domainscreen() {
	myScene2.setScene(otherobjects, 19);
	myScene2.drawScene();
}

void dodatascreen() {
	myScene3.setScene(dataobjects, 12);
	myScene3.drawScene();
}


void initdatascreen() {
	int length = sizeof(datascreengrid) / sizeof(datascreengrid[0]);
	int x = 0;
	int y = 0;
	for (int i = 0; i < length; i++) {
		dataobjects[i] = new StringObject(x, y, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, datascreengrid[i], i);
		y += 30;
	}
	x = 0;
	y = 0;
	for (int i = 0; i < length; i++) {
		dataobjects[i] = new StringObject(x, y, 0xFFFF, FREE_SANS_18PT7B, CENTER_OBJECT, griddata[i], i + length);
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

/*
char *image = "splash.bin";
DisplayObject* splashobjects[1] = {
		new ImageObject(image, SPLASH_LENGTH, SPLASH_HEIGHT, 240, 160, CENTER_OBJECT, 2)
};
Scene splashScene(splashobjects, 1);
*/

/*
void dosplashscene() {
	splashScene.drawScene();
	splashScene.setScene(splashobjects, 1);
}
*/

