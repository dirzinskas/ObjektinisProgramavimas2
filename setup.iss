
[Setup]
AppName=Studentai
AppVersion=v3.0
DefaultDirName={pf}\VU\Vardenis-Pavardenis
DefaultGroupName=VU\Vardenis-Pavardenis
UninstallDisplayIcon={app}\Studentai.exe
OutputBaseFilename=Setup
PrivilegesRequired=admin
Compression=lzma
SolidCompression=yes

[Files]
Source: "main.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Studentai"; Filename: "{app}\main.exe"
Name: "{commondesktop}\Studentai"; Filename: "{app}\.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Create a desktop icon"

[Run]
Filename: "{app}\main.exe"; Description: "Launch My Application"; Flags: nowait postinstall skipifsilent
