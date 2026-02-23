/*
MIT License

Copyright (c) 2017-2023 Nefarius Software Solutions e.U. and Contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#pragma once

//
// Represents the desired target type for the emulated device.
//  
typedef enum _VIGEM_TARGET_TYPE
{
    // 
    // Microsoft Xbox 360 Controller (wired)
    // 
    Xbox360Wired = 0,
    //
    // Sony DualShock 4 (wired)
    // 
    DualShock4Wired = 2, // NOTE: 1 skipped on purpose to maintain compatibility
    //
    // Sony DualSense (wired)
    // 
    DualSenseWired = 3

} VIGEM_TARGET_TYPE, *PVIGEM_TARGET_TYPE;

//
// Possible XUSB report buttons.
// 
typedef enum _XUSB_BUTTON
{
    XUSB_GAMEPAD_DPAD_UP            = 0x0001,
    XUSB_GAMEPAD_DPAD_DOWN          = 0x0002,
    XUSB_GAMEPAD_DPAD_LEFT          = 0x0004,
    XUSB_GAMEPAD_DPAD_RIGHT         = 0x0008,
    XUSB_GAMEPAD_START              = 0x0010,
    XUSB_GAMEPAD_BACK               = 0x0020,
    XUSB_GAMEPAD_LEFT_THUMB         = 0x0040,
    XUSB_GAMEPAD_RIGHT_THUMB        = 0x0080,
    XUSB_GAMEPAD_LEFT_SHOULDER      = 0x0100,
    XUSB_GAMEPAD_RIGHT_SHOULDER     = 0x0200,
    XUSB_GAMEPAD_GUIDE              = 0x0400,
    XUSB_GAMEPAD_A                  = 0x1000,
    XUSB_GAMEPAD_B                  = 0x2000,
    XUSB_GAMEPAD_X                  = 0x4000,
    XUSB_GAMEPAD_Y                  = 0x8000

} XUSB_BUTTON, *PXUSB_BUTTON;

//
// Represents an XINPUT_GAMEPAD-compatible report structure.
// 
typedef struct _XUSB_REPORT
{
    USHORT wButtons;
    BYTE bLeftTrigger;
    BYTE bRightTrigger;
    SHORT sThumbLX;
    SHORT sThumbLY;
    SHORT sThumbRX;
    SHORT sThumbRY;

} XUSB_REPORT, *PXUSB_REPORT;

//
// Initializes a _XUSB_REPORT structure.
// 
VOID FORCEINLINE XUSB_REPORT_INIT(
    _Out_ PXUSB_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(XUSB_REPORT));
}

//
// Values set by output reports on XINPUT_GAMEPAD
//
typedef struct _XUSB_OUTPUT_DATA
{
    UCHAR LargeMotor;
    UCHAR SmallMotor;
    UCHAR LedNumber;
} XUSB_OUTPUT_DATA, *PXUSB_OUTPUT_DATA;

//
// The color value (RGB) of a DualShock 4 Lightbar
// 
typedef struct _DS4_LIGHTBAR_COLOR
{
    //
    // Red part of the Lightbar (0-255).
    //
    UCHAR Red;

    //
    // Green part of the Lightbar (0-255).
    //
    UCHAR Green;

    //
    // Blue part of the Lightbar (0-255).
    //
    UCHAR Blue;

} DS4_LIGHTBAR_COLOR, *PDS4_LIGHTBAR_COLOR;

//
// DualShock 4 digital buttons
// 
typedef enum _DS4_BUTTONS
{
    DS4_BUTTON_THUMB_RIGHT      = 1 << 15,
    DS4_BUTTON_THUMB_LEFT       = 1 << 14,
    DS4_BUTTON_OPTIONS          = 1 << 13,
    DS4_BUTTON_SHARE            = 1 << 12,
    DS4_BUTTON_TRIGGER_RIGHT    = 1 << 11,
    DS4_BUTTON_TRIGGER_LEFT     = 1 << 10,
    DS4_BUTTON_SHOULDER_RIGHT   = 1 << 9,
    DS4_BUTTON_SHOULDER_LEFT    = 1 << 8,
    DS4_BUTTON_TRIANGLE         = 1 << 7,
    DS4_BUTTON_CIRCLE           = 1 << 6,
    DS4_BUTTON_CROSS            = 1 << 5,
    DS4_BUTTON_SQUARE           = 1 << 4

} DS4_BUTTONS, *PDS4_BUTTONS;

//
// DualShock 4 special buttons
// 
typedef enum _DS4_SPECIAL_BUTTONS
{
    DS4_SPECIAL_BUTTON_PS           = 1 << 0,
    DS4_SPECIAL_BUTTON_TOUCHPAD     = 1 << 1

} DS4_SPECIAL_BUTTONS, *PDS4_SPECIAL_BUTTONS;

//
// DualShock 4 directional pad (HAT) values
// 
typedef enum _DS4_DPAD_DIRECTIONS
{
    DS4_BUTTON_DPAD_NONE        = 0x8,
    DS4_BUTTON_DPAD_NORTHWEST   = 0x7,
    DS4_BUTTON_DPAD_WEST        = 0x6,
    DS4_BUTTON_DPAD_SOUTHWEST   = 0x5,
    DS4_BUTTON_DPAD_SOUTH       = 0x4,
    DS4_BUTTON_DPAD_SOUTHEAST   = 0x3,
    DS4_BUTTON_DPAD_EAST        = 0x2,
    DS4_BUTTON_DPAD_NORTHEAST   = 0x1,
    DS4_BUTTON_DPAD_NORTH       = 0x0

} DS4_DPAD_DIRECTIONS, *PDS4_DPAD_DIRECTIONS;

//
// DualShock 4 HID Input report
// 
typedef struct _DS4_REPORT
{
    BYTE bThumbLX;
    BYTE bThumbLY;
    BYTE bThumbRX;
    BYTE bThumbRY;
    USHORT wButtons;
    BYTE bSpecial;
    BYTE bTriggerL;
    BYTE bTriggerR;

} DS4_REPORT, *PDS4_REPORT;

//
// Sets the current state of the D-PAD on a DualShock 4 report.
// 
VOID FORCEINLINE DS4_SET_DPAD(
    _Out_ PDS4_REPORT Report,
    _In_ DS4_DPAD_DIRECTIONS Dpad
)
{
    Report->wButtons &= ~0xF;
    Report->wButtons |= (USHORT)Dpad;
}

VOID FORCEINLINE DS4_REPORT_INIT(
    _Out_ PDS4_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(DS4_REPORT));

    Report->bThumbLX = 0x80;
    Report->bThumbLY = 0x80;
    Report->bThumbRX = 0x80;
    Report->bThumbRY = 0x80;

    DS4_SET_DPAD(Report, DS4_BUTTON_DPAD_NONE);
}

//
// DualSense digital buttons (same bit positions as DS4)
// 
typedef enum _DUALSENSE_BUTTONS
{
    DUALSENSE_BUTTON_THUMB_RIGHT      = 1 << 15,
    DUALSENSE_BUTTON_THUMB_LEFT       = 1 << 14,
    DUALSENSE_BUTTON_OPTIONS          = 1 << 13,
    DUALSENSE_BUTTON_CREATE           = 1 << 12,
    DUALSENSE_BUTTON_TRIGGER_RIGHT    = 1 << 11,
    DUALSENSE_BUTTON_TRIGGER_LEFT     = 1 << 10,
    DUALSENSE_BUTTON_SHOULDER_RIGHT   = 1 << 9,
    DUALSENSE_BUTTON_SHOULDER_LEFT    = 1 << 8,
    DUALSENSE_BUTTON_TRIANGLE         = 1 << 7,
    DUALSENSE_BUTTON_CIRCLE           = 1 << 6,
    DUALSENSE_BUTTON_CROSS            = 1 << 5,
    DUALSENSE_BUTTON_SQUARE           = 1 << 4

} DUALSENSE_BUTTONS, *PDUALSENSE_BUTTONS;

//
// DualSense special buttons
// 
typedef enum _DUALSENSE_SPECIAL_BUTTONS
{
    DUALSENSE_SPECIAL_BUTTON_PS           = 1 << 0,
    DUALSENSE_SPECIAL_BUTTON_TOUCHPAD     = 1 << 1,
    DUALSENSE_SPECIAL_BUTTON_MUTE         = 1 << 2

} DUALSENSE_SPECIAL_BUTTONS, *PDUALSENSE_SPECIAL_BUTTONS;

//
// DualSense adaptive trigger effect modes
//
typedef enum _DUALSENSE_TRIGGER_EFFECT_MODE
{
    DUALSENSE_TRIGGER_EFFECT_OFF               = 0x00,
    DUALSENSE_TRIGGER_EFFECT_CONTINUOUS        = 0x01,
    DUALSENSE_TRIGGER_EFFECT_SECTION           = 0x02,
    DUALSENSE_TRIGGER_EFFECT_VIBRATION         = 0x06,
    DUALSENSE_TRIGGER_EFFECT_CALIBRATION       = 0x21,
    DUALSENSE_TRIGGER_EFFECT_FEEDBACK_VIBRATE  = 0x25,
    DUALSENSE_TRIGGER_EFFECT_MULTI_VIBRATE     = 0x26,
    DUALSENSE_TRIGGER_EFFECT_SLOPE_FEEDBACK    = 0xFC
} DUALSENSE_TRIGGER_EFFECT_MODE, *PDUALSENSE_TRIGGER_EFFECT_MODE;

//
// DualSense adaptive trigger effect parameters
//
typedef struct _DUALSENSE_TRIGGER_EFFECT
{
    UCHAR Mode;
    UCHAR Params[6];
} DUALSENSE_TRIGGER_EFFECT, *PDUALSENSE_TRIGGER_EFFECT;

//
// DualSense directional pad values (same as DS4)
// 
typedef enum _DUALSENSE_DPAD_DIRECTIONS
{
    DUALSENSE_BUTTON_DPAD_NONE        = 0x8,
    DUALSENSE_BUTTON_DPAD_NORTHWEST   = 0x7,
    DUALSENSE_BUTTON_DPAD_WEST        = 0x6,
    DUALSENSE_BUTTON_DPAD_SOUTHWEST   = 0x5,
    DUALSENSE_BUTTON_DPAD_SOUTH       = 0x4,
    DUALSENSE_BUTTON_DPAD_SOUTHEAST   = 0x3,
    DUALSENSE_BUTTON_DPAD_EAST        = 0x2,
    DUALSENSE_BUTTON_DPAD_NORTHEAST   = 0x1,
    DUALSENSE_BUTTON_DPAD_NORTH       = 0x0

} DUALSENSE_DPAD_DIRECTIONS, *PDUALSENSE_DPAD_DIRECTIONS;

//
// DualSense HID Input report (simplified)
// Byte order matches the HID report: sticks, triggers, buttons
// 
typedef struct _DUALSENSE_REPORT
{
    BYTE bThumbLX;
    BYTE bThumbLY;
    BYTE bThumbRX;
    BYTE bThumbRY;
    BYTE bTriggerL;
    BYTE bTriggerR;
    USHORT wButtons;
    BYTE bSpecial;

} DUALSENSE_REPORT, *PDUALSENSE_REPORT;

//
// Sets the current state of the D-PAD on a DualSense report.
// 
VOID FORCEINLINE DUALSENSE_SET_DPAD(
    _Out_ PDUALSENSE_REPORT Report,
    _In_ DUALSENSE_DPAD_DIRECTIONS Dpad
)
{
    Report->wButtons &= ~0xF;
    Report->wButtons |= (USHORT)Dpad;
}

VOID FORCEINLINE DUALSENSE_REPORT_INIT(
    _Out_ PDUALSENSE_REPORT Report
)
{
    RtlZeroMemory(Report, sizeof(DUALSENSE_REPORT));

    Report->bThumbLX = 0x80;
    Report->bThumbLY = 0x80;
    Report->bThumbRX = 0x80;
    Report->bThumbRY = 0x80;

    DUALSENSE_SET_DPAD(Report, DUALSENSE_BUTTON_DPAD_NONE);
}

#include <pshpack1.h> // pack structs tightly

//
// DualSense touchpad structure (same layout as DS4)
//
typedef struct _DUALSENSE_TOUCH
{
    BYTE bPacketCounter;
    BYTE bIsUpTrackingNum1;
    BYTE bTouchData1[3];
    BYTE bIsUpTrackingNum2;
    BYTE bTouchData2[3];
} DUALSENSE_TOUCH, * PDUALSENSE_TOUCH;

//
// DualSense complete HID Input report
//
typedef struct _DUALSENSE_REPORT_EX
{
    union
    {
        struct
        {
            BYTE bThumbLX;
            BYTE bThumbLY;
            BYTE bThumbRX;
            BYTE bThumbRY;
            BYTE bTriggerL;
            BYTE bTriggerR;
            BYTE bCounter;
            USHORT wButtons;
            BYTE bSpecial;
            BYTE _bReserved0;
            ULONG dwTimestamp;
            SHORT wGyroX;
            SHORT wGyroY;
            SHORT wGyroZ;
            SHORT wAccelX;
            SHORT wAccelY;
            SHORT wAccelZ;
            ULONG dwSensorTimestamp;
            BYTE bTemperature;
            DUALSENSE_TOUCH sCurrentTouch;
            DUALSENSE_TOUCH sPreviousTouch;
            BYTE _bReserved1;
            ULONG dwCRC32;
        } Report;

        UCHAR ReportBuffer[63];
    };
} DUALSENSE_REPORT_EX, *PDUALSENSE_REPORT_EX;

typedef struct _DUALSENSE_OUTPUT_BUFFER
{
    _Out_ UCHAR Buffer[64];

} DUALSENSE_OUTPUT_BUFFER, *PDUALSENSE_OUTPUT_BUFFER;

#include <poppack.h>
// Values set by output reports on DualShock 4
//
typedef struct _DS4_OUTPUT_DATA
{
    UCHAR LargeMotor;
    UCHAR SmallMotor;
    DS4_LIGHTBAR_COLOR LightbarColor;
} DS4_OUTPUT_DATA, *PDS4_OUTPUT_DATA;

#include <pshpack1.h> // pack structs tightly
//
// DualShock 4 HID Touchpad structure
//
typedef struct _DS4_TOUCH
{
    BYTE bPacketCounter;    // timestamp / packet counter associated with touch event
    BYTE bIsUpTrackingNum1; // 0 means down; active low
                            // unique to each finger down, so for a lift and repress the value is incremented
    BYTE bTouchData1[3];    // Two 12 bits values (for X and Y) 
                            // middle byte holds last 4 bits of X and the starting 4 bits of Y
    BYTE bIsUpTrackingNum2; // second touch data immediately follows data of first touch 
    BYTE bTouchData2[3];    // resolution is 1920x943
} DS4_TOUCH, * PDS4_TOUCH;

//
// DualShock 4 v1 complete HID Input report
//
typedef struct _DS4_REPORT_EX
{
	union
	{
		struct
		{
			BYTE bThumbLX;
			BYTE bThumbLY;
			BYTE bThumbRX;
			BYTE bThumbRY;
			USHORT wButtons;
			BYTE bSpecial;
			BYTE bTriggerL;
			BYTE bTriggerR;
			USHORT wTimestamp;
			BYTE bBatteryLvl;
			SHORT wGyroX;
			SHORT wGyroY;
			SHORT wGyroZ;
			SHORT wAccelX;
			SHORT wAccelY;
			SHORT wAccelZ;
			BYTE _bUnknown1[5];
			BYTE bBatteryLvlSpecial;
			// really should have a enum to show everything that this can represent (USB charging, battery level; EXT, headset, microphone connected)
			BYTE _bUnknown2[2];
			BYTE bTouchPacketsN; // 0x00 to 0x03 (USB max)
			DS4_TOUCH sCurrentTouch;
			DS4_TOUCH sPreviousTouch[2];
		} Report;

		UCHAR ReportBuffer[63];
	};
} DS4_REPORT_EX, *PDS4_REPORT_EX;

typedef struct _DS4_OUTPUT_BUFFER
{
	//
	// The output report buffer
	// 
	_Out_ UCHAR Buffer[64];
	
} DS4_OUTPUT_BUFFER, *PDS4_OUTPUT_BUFFER;

#include <poppack.h>
