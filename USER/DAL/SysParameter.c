/*
*系统级参数，出厂之后一般不改变的参数。但是注册码要变化
*/
#include "SysParameter.h"
#include "FileOperate.h"
#include "PublicFunction.h"

char _superPass[]="super";
//系统参数实例
SysParameterStruct SysParameter;
ControlMPStruct ControlMPMsg;

