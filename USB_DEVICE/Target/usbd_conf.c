/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : Target/usbd_conf.c
  * @version        : v1.0_Cube
  * @brief          : This file implements the board support package for the USB device library
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"
#include "usbd_def.h"
#include "usbd_core.h"
#include "usbd_cdc.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

FreeMarker template error (DEBUG mode; use RETHROW in production!):
Template inclusion failed (for parameter value "MXTmpFiles/usb_otg_fs_vars.tmp"):
Template not found for name "MXTmpFiles/usb_otg_fs_vars.tmp".
The name was interpreted by this TemplateLoader: MultiTemplateLoader(loader1 = FileTemplateLoader(baseDir="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display", canonicalBasePath="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display\"), loader2 = FileTemplateLoader(baseDir="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display", canonicalBasePath="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display\"), loader3 = FileTemplateLoader(baseDir="C:\Users\cathy\AppData\Local\Programs\STM32CubeMX\db\templates", canonicalBasePath="C:\Users\cathy\AppData\Local\Programs\STM32CubeMX\db\templates\")).

----
FTL stack trace ("~" means nesting-related):
	- Failed at: #include mxTmpFolder + "/usb_otg_fs_v...  [in template "usbdconf_h7_c.ftl" at line 99, column 1]
----

Java stack trace (for programmers):
----
freemarker.core._MiscTemplateException: [... Exception message was already printed; see it above ...]
	at freemarker.core.Include.accept(Include.java:164)
	at freemarker.core.Environment.visit(Environment.java:334)
	at freemarker.core.Environment.visit(Environment.java:340)
	at freemarker.core.Environment.visit(Environment.java:340)
	at freemarker.core.Environment.process(Environment.java:313)
	at freemarker.template.Template.process(Template.java:383)
	at com.st.microxplorer.codegenerator.CodeEngine.freemarkerDo(CodeEngine.java:454)
	at com.st.microxplorer.codegenerator.CodeEngine.genCode(CodeEngine.java:303)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateOutputCode(CodeGenerator.java:6687)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateSpecificCode(CodeGenerator.java:5473)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateSpecificCodeFile(CodeGenerator.java:1905)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateCodeFiles(CodeGenerator.java:2285)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateDefaultConfig(CodeGenerator.java:11373)
	at com.st.microxplorer.codegenerator.CodeGenerator.generateCode(CodeGenerator.java:1611)
	at com.st.microxplorer.plugins.projectmanager.engine.ProjectBuilder.generateCode(ProjectBuilder.java:3468)
	at com.st.microxplorer.plugins.projectmanager.engine.ProjectBuilder.createCode(ProjectBuilder.java:2271)
	at com.st.microxplorer.plugins.projectmanager.engine.ProjectBuilder.createProject(ProjectBuilder.java:821)
	at com.st.microxplorer.plugins.projectmanager.engine.GenerateProjectThread.run(GenerateProjectThread.java:61)
Caused by: freemarker.template.TemplateNotFoundException: Template not found for name "MXTmpFiles/usb_otg_fs_vars.tmp".
The name was interpreted by this TemplateLoader: MultiTemplateLoader(loader1 = FileTemplateLoader(baseDir="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display", canonicalBasePath="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display\"), loader2 = FileTemplateLoader(baseDir="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display", canonicalBasePath="C:\Users\cathy\STM32CubeIDE\workspace_1.17.0\G26 Display\"), loader3 = FileTemplateLoader(baseDir="C:\Users\cathy\AppData\Local\Programs\STM32CubeMX\db\templates", canonicalBasePath="C:\Users\cathy\AppData\Local\Programs\STM32CubeMX\db\templates\")).
	at freemarker.template.Configuration.getTemplate(Configuration.java:2869)
	at freemarker.core.Environment.getTemplateForInclusion(Environment.java:2883)
	at freemarker.core.Include.accept(Include.java:162)
	... 17 more
