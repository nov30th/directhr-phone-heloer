

#define MyAppName "Direct HR Softphone"
#define MyAppVerName "Direct HR Softphone"
#define MyAppPublisher "Vincent Qiu"
#define MyAppURL "http://www.directhr.net"
#define MyAppExeName "eyeBeam.exe"
#define MyAppCrack "Active Softphone"
#define MyAppCrackExeName "vincent_qiu_softphone_luncher.exe"
#define MyAgent "Softphone Agent"
#define MyAppAgentExeName "DHRSoftphone.SoftphoneAgent_QZJ.exe"
;#define MyChromePlugin "plugins\dhr_dialer.crx"
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
PrivilegesRequired=admin

;signtool=digitsign
;sign /n $qzhongjie qiu$q /d "Direct HR Softphone Agent" /du "http://www.directhr.net" /t http://timestamp.verisign.com/scripts/timstamp.dll $f


AppId={{8DF33044-AD82-4396-B2F2-67CB1C3019D8}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\Softphone
DisableDirPage=yes
DefaultGroupName={#MyAppName}
DisableProgramGroupPage=yes
OutputDir=..\Finished_Setup_Files
OutputBaseFilename="setup"
SetupIconFile=..\For_Installer\20110811125146294_easyicon_cn_48.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Languages\English.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "startupicon"; Description: "Run softphone at startup"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "..\eyeBeam\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{#MyAppCrack}"; Filename: "{app}\{#MyAppCrackExeName}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{commondesktop}\{#MyAppCrack}"; Filename: "{app}\{#MyAppCrackExeName}"; Tasks: desktopicon
Name: "{commondesktop}\{#MyAgent}"; Filename: "{app}\{#MyAppAgentExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon
Name: "{commonstartup}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: startupicon
Name: "{commonstartup}\{#MyAgent}"; Filename: "{app}\{#MyAppAgentExeName}"; Tasks: startupicon


[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent
Filename: "{app}\{#MyAppCrackExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppCrack, "&", "&&")}}"; Flags: nowait postinstall
Filename: "{app}\{#MyAppAgentExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAgent, "&", "&&")}}"; Flags: nowait postinstall
;Filename: "{app}\{#MyChromePlugin}"; Description: "{cm:LaunchProgram,{#StringChange("Install Chrome Plugin", "&", "&&")}}"; Flags: nowait postinstall

[InstallDelete]
Type: files; Name: "{userdocs}\AgentOptions.ini"

[Code]
//安装前判断是否有进程正在运行，istask.dll文件与打包的exe文件一起
function RunTask(FileName: string; bFullpath: Boolean): Boolean;
external 'RunTask@files:ISTask.dll stdcall delayload';
function KillTask(ExeFileName: string): Integer;
external 'KillTask@files:ISTask.dll stdcall delayload';

function InitializeSetup(): Boolean;
begin
 Result:= true;
 if RunTask('{#MyAppExeName}', false) or RunTask('{#MyAppAgentExeName}', false) or RunTask('{#MyAppCrackExeName}', false) then
 begin
 if MsgBox('Oh! I have decected {#MyAppName} or one of its part is still running！'#13''#13'Click “Yes/是”to close this program and continue setup；'#13''#13'Click “No/否”to cancel this setup', mbConfirmation, MB_YESNO) = IDYES then
 begin
 KillTask('{#MyAppExeName}');
 KillTask('{#MyAppAgentExeName}');
 KillTask('{#MyAppCrackExeName}');
 Result:= true;
 end
 else
 Result:= false;
 end
 else Result:= true;
end;



// 卸载前判断进程是否在运行
function RunTaskU(FileName: string; bFullpath: Boolean): Boolean;
 external 'RunTask@{app}/ISTask.dll stdcall delayload uninstallonly';
function KillTaskU(ExeFileName: string): Integer;
 external 'KillTask@{app}/ISTask.dll stdcall delayload uninstallonly';

function InitializeUninstall(): Boolean;
 begin
 Result:= true;
 if RunTaskU('{#MyAppExeName}', false) then
 begin
if MsgBox('Oh! I have decected {#MyAppName} or one of its part is still running！'#13''#13'Click “Yes/是”to close this program and continue uninstall；'#13''#13'Click “No/否”to cancel this uninstall', mbConfirmation, MB_YESNO) = IDYES then
 begin
 KillTaskU('{#MyAppExeName}');
 Result:= true;
 end
 else
 Result:= false;
 end
 else
 Result:= true;
 UnloadDll(ExpandConstant('{app}/ISTask.dll'));

 end;
