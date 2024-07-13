
// JeopardyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Jeopardy.h"
#include "JeopardyDlg.h"
#include "QADialog.h"
#include "RtMidi.h"
#include "DailyDouble.h"
#include <Mmsystem.h>
//#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

#if defined(WIN32)
#include <windows.h>
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <vector>
#include <string>


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };
	RtMidiOut midiout;
	std::vector<unsigned char> message;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void PlayNote(int note, int duration, int instrument);
	void KeyDown(int note, int instrument);
	void KeyUp(int note, int instrument);

	enum Notes
	{
		Note_1C  = 24,
		Note_1DF = 25,
		Note_1D  = 26,
		Note_1EF = 27,
		Note_1E  = 28,
		Note_1F  = 29,
		Note_1FS = 30,
		Note_1G  = 31,
		Note_1AF = 32,
		Note_1A  = 33,
		Note_1BF = 34,
		Note_1B  = 35,
		Note_2C  = 36,
		Note_2DF = 37,
		Note_2D  = 38,
		Note_2EF = 39,
		Note_2E  = 40,
		Note_2F  = 41,
		Note_2FS = 42,
		Note_2G  = 43,
		Note_2AF = 44,
		Note_2A  = 45,
		Note_2BF = 46,
		Note_2B  = 47,
		Note_3C  = 48,
		Note_3DF = 49,
		Note_3D  = 50,
		Note_3EF = 51,
		Note_3E  = 52,
		Note_3F  = 53,
		Note_3FS = 54,
		Note_3G  = 55,
		Note_3AF = 56,
		Note_3A  = 57,
		Note_3BF = 58,
		Note_3B  = 59,
		Note_4C  = 60,
		Note_4DF = 61,
		Note_4D  = 62,
		Note_4EF = 63,
		Note_4E  = 64,
		Note_4F  = 65,
		Note_4FS = 66,
		Note_4G  = 67,
		Note_4AF = 68,
		Note_4A  = 69,
		Note_4BF = 70,
		Note_4B  = 71,
		Note_5C  = 72,
		Note_5DF = 73,
		Note_5D  = 74,
		Note_5EF = 75,
		Note_5E  = 76,
		Note_5F  = 77,
		Note_5FS = 78,
		Note_5G  = 79,
		Note_5AF = 80,
		Note_5A  = 81,
		Note_5BF = 82,
		Note_5B  = 83,
		Note_6C  = 84,
		Note_6DF = 85,
		Note_6D  = 86,
		Note_6EF = 87,
		Note_6E  = 88,
		Note_6F  = 89,
		Note_6FS = 90,
		Note_6G  = 91,
		Note_6AF = 92,
		Note_6A  = 93,
		Note_6BF = 94,
		Note_6B  = 95,
		Note_7C  = 96,
		Note_7DF = 97,
		Note_7D  = 98,
		Note_7EF = 99,
		Note_7E  = 100,
		Note_7F  = 101,
		Note_7FS = 102,
		Note_7G  = 103,
		Note_7AF = 104,
		Note_7A  = 105,
		Note_7BF = 106,
		Note_7B  = 107,
		Note_8C  = 108,
		Note_8DF = 109,
		Note_8D  = 110,
		Note_8EF = 111,
		Note_8E  = 112,
		Note_8F  = 113,
		Note_8FS = 114,
		Note_8G  = 115,
		Note_8AF = 116,
		Note_8A  = 117,
		Note_8BF = 118,
		Note_8B  = 119,
		Note_9C  = 120
	};

	enum MidiCommands
	{
		MidiProgramChange = 192,
		MidiVolumeSet = 176,
		MidiNoteStart = 144,
		MidiNoteStop = 128,
		MidiNoteVelocity = 127,
		MidiInstrumentAcousticGrandPiano = 0,
		MidiInstrumentBrightAcousticPiano = 1,
		MidiInstrumentElectricGrandPiano = 2,
		MidiInstrumentHonkyTonkPiano = 3,
		MidiInstrumentElectricPiano1 = 4,
		MidiInstrumentElectricPiano2 = 5,
		MidiInstrumentHarpsicord = 6,
		MidiInstrumentClavinet = 7,
		MidiInstrumentCelesta = 8,
		MidiInstrumentGlockenspiel = 9,
		MidiInstrumentMusicBox = 10,
		MidiInstrumentVibraphone = 11,
		MidiInstrumentMarimba = 12,
		MidiInstrumentXylophone = 13,
		MidiInstrumentTublarBells = 14,
		MidiInstrumentDulcimer = 15,
		MidiInstrumentDrawbarOrgan = 16,
		MidiInstrumentPercussiveOrgan = 17,
		MidiInstrumentRockOrgan = 18,
		MidiInstrumentChurchOrgan = 19,
		MidiInstrumentReedOrgan = 20,
		MidiInstrumentAccordion = 21,
		MidiInstrumentHarmonica = 22,
		MidiInstrumentTangoAccordion = 23,
		MidiInstrumentAcousticGuitarNylon = 24,
		MidiInstrumentAcousticGuitarSteel = 25,
		MidiInstrumentElectricGuitarJazz = 26,
		MidiInstrumentElectricGuitarClean = 27,
		MidiInstrumentElectricGuitarMuted = 28,
		MidiInstrumentOverdrivenGuitar = 29,
		MidiInstrumentDistortionGuitar = 30,
		MidiInstrumentGuitarHarmonics = 31,
		MidiInstrumentAcousticBass = 32,
		MidiInstrumentElectricBassFinger = 33,
		MidiInstrumentElectricBassPick = 34,
		MidiInstrumentFretlessBass = 35,
		MidiInstrumentSlapBass1 = 36,
		MidiInstrumentSlapBass2 = 37,
		MidiInstrumentSynthBass1 = 38,
		MidiInstrumentSynthBass2 = 39,
		MidiInstrumentViolin = 40,
		MidiInstrumentViola = 41,
		MidiInstrumentCello = 42,
		MidiInstrumentContrabass = 43,
		MidiInstrumentTremoloStrings = 44,
		MidiInstrumentPizzicatoStrings = 45,
		MidiInstrumentOrchestralHarp = 46,
		MidiInstrumentTimpani = 47,
		MidiInstrumentStringEnsemble1 = 48,
		MidiInstrumentStringEnsemble2 = 49,
		MidiInstrumentSynthString1 = 50,
		MidiInstrumentSynthStrings2 = 51,
		MidiInstrumentChoirAahs = 52,
		MidiInstrumentVoiceOohs = 53,
		MidiInstrumentSynthVoice = 54,
		MidiInstrumentOrchestraHit = 55,
		MidiInstrumentTrumpet = 56,
		MidiInstrumentTrombone = 57,
		MidiInstrumentTuba = 58,
		MidiInstrumentMutedTrumpet = 59,
		MidiInstrumentFrenchHorn = 60,
		MidiInstrumentBrassSection = 61,
		MidiInstrumentSynthBrass1 = 62,
		MidiInstrumentSynthBrass2 = 63,
		MidiInstrumentSopranoSax = 64,
		MidiInstrumentAltoSax = 65,
		MidiInstrumentTenorSax = 66,
		MidiInstrumentBaritoneSax = 67,
		MidiInstrumentOboe = 68,
		MidiInstrumentEnglishHorn = 69,
		MidiInstrumentBassoon = 70,
		MidiInstrumentClarinet = 71,
		MidiInstrumentPiccolo = 72,
		MidiInstrumentFlute = 73,
		MidiInstrumentRecorder = 74,
		MidiInstrumentPanFlute = 75,
		MidiInstrumentBlownBottle = 76,
		MidiInstrumentShakuhachi = 77,
		MidiInstrumentWhistle = 78,
		MidiInstrumentOcarina = 79,
		MidiInstrumentLead1Square = 80,
		MidiInstrumentLead2Sawtooth = 81,
		MidiInstrumentLead3Calliope = 82,
		MidiInstrumentLead4Chiff = 83,
		MidiInstrumentLead5Charang = 84,
		MidiInstrumentLead6Voice = 85,
		MidiInstrumentLead7Fifths = 86,
		MidiInstrumentLead8BassLead = 87,
		MidiInstrumentPad1NewAge = 88,
		MidiInstrumentPad2Warm = 89,
		MidiInstrumentPad3PolySynth = 90,
		MidiInstrumentPad4Choir = 91,
		MidiInstrumentPad5Bowed = 92,
		MidiInstrumentPad6Metallic = 93,
		MidiInstrumentPad7Halo = 94,
		MidiInstrumentPad8Sweep = 95,
		MidiInstrumentFX1Rain = 96,
		MidiInstrumentFX2Soundtrack = 97,
		MidiInstrumentFX3Crystal = 98,
		MidiInstrumentFX4Atmosphere = 99,
		MidiInstrumentFX5Brightness = 100,
		MidiInstrumentFX6Goblins = 101,
		MidiInstrumentFX7Echoes = 102,
		MidiInstrumentFX8SciFi = 103,
		MidiInstrumentSitar = 104,
		MidiInstrumentBanjo = 105,
		MidiInstrumentShamisen = 106,
		MidiInstrumentKoto = 107,
		MidiInstrumentKalimba = 108,
		MidiInstrumentBagPipe = 109,
		MidiInstrumentFiddle = 110,
		MidiInstrumentShanai = 111,
		MidiInstrumentTinkleBell = 112,
		MidiInstrumentAgogo = 113,
		MidiInstrumentSteelDrums = 114,
		MidiInstrumentWoodblock = 115,
		MidiInstrumentTaikoDrum = 116,
		MidiInstrumentMelodicTom = 117,
		MidiInstrumentSynthDrum = 118,
		MidiInstrumentReverseCymbal = 119,
		MidiInstrumentGutiarFretNoise = 120,
		MidiInstrumentBreathNoise = 121,
		MidiInstrumentSeashore = 122,
		MidiInstrumentBirdTweet = 123,
		MidiInstrumentTelephoneRing = 124,
		MidiInstrumentHelicopter = 125,
		MidiInstrumentApplause = 126,
		MidiInstrumentGunShot = 127
	};
// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest();

	int GetIntFromCString(CString csInput);
	void RunINITest2();
	void PlayMusicList(CString csMusicList);
	void PlayOdeToJoy();
	void PlayMarineCorp();
	void PlayThemeChord();

	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonF();
	afx_msg void OnBnClickedButtonG();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonCHigh();
	afx_msg void OnBnClickedButtonCSharp();
	afx_msg void OnBnClickedButtonEFlat();
	afx_msg void OnBnClickedButtonFSharp();
	afx_msg void OnBnClickedButtonAFlat();
	afx_msg void OnBnClickedButtonBFlat();

	LPCWSTR MUSIC;
	LPCWSTR NOTELIST;
	LPCWSTR THEME;

	int m_nDuration;

	afx_msg void OnBnClickedButtonTheme();
	CListBox ctrl_instrument_list;
	afx_msg void OnBnClickedButton5c();
	afx_msg void OnBnClickedButton5d();
	afx_msg void OnBnClickedButton5e();
	afx_msg void OnBnClickedButton5f();
	afx_msg void OnBnClickedButton5g();
	afx_msg void OnBnClickedButton5a();
	afx_msg void OnBnClickedButton5b();
	afx_msg void OnBnClickedButton5ch();
	afx_msg void OnBnClickedButton5cs();
	afx_msg void OnBnClickedButton5ef();
	afx_msg void OnBnClickedButton5fs();
	afx_msg void OnBnClickedButton5af();
	afx_msg void OnBnClickedButton5bf();
	afx_msg void OnBnClickedButton1c();
	afx_msg void OnBnClickedButton1d();
	afx_msg void OnBnClickedButton1e();
	afx_msg void OnBnClickedButton1f();
	afx_msg void OnBnClickedButton1g();
	afx_msg void OnBnClickedButton1a();
	afx_msg void OnBnClickedButton1b();
	afx_msg void OnBnClickedButton1ch();
	afx_msg void OnBnClickedButton1cs();
	afx_msg void OnBnClickedButton1ef();
	afx_msg void OnBnClickedButton1fs();
	afx_msg void OnBnClickedButton1af();
	afx_msg void OnBnClickedButton1bf();
	afx_msg void OnBnClickedButton2c();
	afx_msg void OnBnClickedButton2d();
	afx_msg void OnBnClickedButton2e();
	afx_msg void OnBnClickedButton2f();
	afx_msg void OnBnClickedButton2g();
	afx_msg void OnBnClickedButton2a();
	afx_msg void OnBnClickedButton2b();
	afx_msg void OnBnClickedButton2ch();
	afx_msg void OnBnClickedButton2cs();
	afx_msg void OnBnClickedButton2ef();
	afx_msg void OnBnClickedButton2fs();
	afx_msg void OnBnClickedButton2af();
	afx_msg void OnBnClickedButton2bf();
	afx_msg void OnBnClickedButton3c();
	afx_msg void OnBnClickedButton3d();
	afx_msg void OnBnClickedButton3e();
	afx_msg void OnBnClickedButton3f();
	afx_msg void OnBnClickedButton3g();
	afx_msg void OnBnClickedButton3a();
	afx_msg void OnBnClickedButton3b();
	afx_msg void OnBnClickedButton3ch();
	afx_msg void OnBnClickedButton3cs();
	afx_msg void OnBnClickedButton3ef();
	afx_msg void OnBnClickedButton3fs();
	afx_msg void OnBnClickedButton3af();
	afx_msg void OnBnClickedButton3bf();
	afx_msg void OnBnClickedButton6c();
	afx_msg void OnBnClickedButton6d();
	afx_msg void OnBnClickedButton6e();
	afx_msg void OnBnClickedButton6f();
	afx_msg void OnBnClickedButton6g();
	afx_msg void OnBnClickedButton6a();
	afx_msg void OnBnClickedButton6b();
	afx_msg void OnBnClickedButton6ch();
	afx_msg void OnBnClickedButton6cs();
	afx_msg void OnBnClickedButton6ef();
	afx_msg void OnBnClickedButton6fs();
	afx_msg void OnBnClickedButton6af();
	afx_msg void OnBnClickedButton6bf();
	afx_msg void OnBnClickedButton7c();
	afx_msg void OnBnClickedButton7d();
	afx_msg void OnBnClickedButton7e();
	afx_msg void OnBnClickedButton7f();
	afx_msg void OnBnClickedButton7g();
	afx_msg void OnBnClickedButton7a();
	afx_msg void OnBnClickedButton7b();
	afx_msg void OnBnClickedButton7ch();
	afx_msg void OnBnClickedButton7cs();
	afx_msg void OnBnClickedButton7ef();
	afx_msg void OnBnClickedButton7fs();
	afx_msg void OnBnClickedButton7af();
	afx_msg void OnBnClickedButton7bf();
	afx_msg void OnBnClickedButton8c();
	afx_msg void OnBnClickedButton8d();
	afx_msg void OnBnClickedButton8e();
	afx_msg void OnBnClickedButton8f();
	afx_msg void OnBnClickedButton8g();
	afx_msg void OnBnClickedButton8a();
	afx_msg void OnBnClickedButton8b();
	afx_msg void OnBnClickedButton8ch();
	afx_msg void OnBnClickedButton8cs();
	afx_msg void OnBnClickedButton8ef();
	afx_msg void OnBnClickedButton8fs();
	afx_msg void OnBnClickedButton8af();
	afx_msg void OnBnClickedButton8bf();
};
///////////////////////////////////////////////////////////////////////////////
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	MUSIC = _T("MUSIC");
	NOTELIST = _T("NOTELIST");
	THEME = _T("THEME");
	midiout.openPort(0);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
///////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_Test, &CAboutDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_BUTTON_C, &CAboutDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, &CAboutDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_E, &CAboutDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_F, &CAboutDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_G, &CAboutDlg::OnBnClickedButtonG)
	ON_BN_CLICKED(IDC_BUTTON_A, &CAboutDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &CAboutDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C_HIGH, &CAboutDlg::OnBnClickedButtonCHigh)
	ON_BN_CLICKED(IDC_BUTTON_C_SHARP, &CAboutDlg::OnBnClickedButtonCSharp)
	ON_BN_CLICKED(IDC_BUTTON_E_FLAT, &CAboutDlg::OnBnClickedButtonEFlat)
	ON_BN_CLICKED(IDC_BUTTON_F_SHARP, &CAboutDlg::OnBnClickedButtonFSharp)
	ON_BN_CLICKED(IDC_BUTTON_A_FLAT, &CAboutDlg::OnBnClickedButtonAFlat)
	ON_BN_CLICKED(IDC_BUTTON_B_FLAT, &CAboutDlg::OnBnClickedButtonBFlat)
	ON_BN_CLICKED(IDC_BUTTON_THEME, &CAboutDlg::OnBnClickedButtonTheme)
	ON_BN_CLICKED(IDC_BUTTON_5C, &CAboutDlg::OnBnClickedButton5c)
	ON_BN_CLICKED(IDC_BUTTON_5D, &CAboutDlg::OnBnClickedButton5d)
	ON_BN_CLICKED(IDC_BUTTON_5E, &CAboutDlg::OnBnClickedButton5e)
	ON_BN_CLICKED(IDC_BUTTON_5F, &CAboutDlg::OnBnClickedButton5f)
	ON_BN_CLICKED(IDC_BUTTON_5G, &CAboutDlg::OnBnClickedButton5g)
	ON_BN_CLICKED(IDC_BUTTON_5A, &CAboutDlg::OnBnClickedButton5a)
	ON_BN_CLICKED(IDC_BUTTON_5B, &CAboutDlg::OnBnClickedButton5b)
	ON_BN_CLICKED(IDC_BUTTON_5CH, &CAboutDlg::OnBnClickedButton5ch)
	ON_BN_CLICKED(IDC_BUTTON5CS, &CAboutDlg::OnBnClickedButton5cs)
	ON_BN_CLICKED(IDC_BUTTON_5EF, &CAboutDlg::OnBnClickedButton5ef)
	ON_BN_CLICKED(IDC_BUTTON_5FS, &CAboutDlg::OnBnClickedButton5fs)
	ON_BN_CLICKED(IDC_BUTTON5AF, &CAboutDlg::OnBnClickedButton5af)
	ON_BN_CLICKED(IDC_BUTTON_5BF, &CAboutDlg::OnBnClickedButton5bf)
	ON_BN_CLICKED(IDC_BUTTON_1C, &CAboutDlg::OnBnClickedButton1c)
	ON_BN_CLICKED(IDC_BUTTON_1D, &CAboutDlg::OnBnClickedButton1d)
	ON_BN_CLICKED(IDC_BUTTON_1E, &CAboutDlg::OnBnClickedButton1e)
	ON_BN_CLICKED(IDC_BUTTON_1F, &CAboutDlg::OnBnClickedButton1f)
	ON_BN_CLICKED(IDC_BUTTON_1G, &CAboutDlg::OnBnClickedButton1g)
	ON_BN_CLICKED(IDC_BUTTON_1A, &CAboutDlg::OnBnClickedButton1a)
	ON_BN_CLICKED(IDC_BUTTON_1B, &CAboutDlg::OnBnClickedButton1b)
	ON_BN_CLICKED(IDC_BUTTON_1CH, &CAboutDlg::OnBnClickedButton1ch)
	ON_BN_CLICKED(IDC_BUTTON_1CS, &CAboutDlg::OnBnClickedButton1cs)
	ON_BN_CLICKED(IDC_BUTTON_1EF, &CAboutDlg::OnBnClickedButton1ef)
	ON_BN_CLICKED(IDC_BUTTON_1FS, &CAboutDlg::OnBnClickedButton1fs)
	ON_BN_CLICKED(IDC_BUTTON_1AF, &CAboutDlg::OnBnClickedButton1af)
	ON_BN_CLICKED(IDC_BUTTON_1BF, &CAboutDlg::OnBnClickedButton1bf)
	ON_BN_CLICKED(IDC_BUTTON_2C, &CAboutDlg::OnBnClickedButton2c)
	ON_BN_CLICKED(IDC_BUTTON_2D, &CAboutDlg::OnBnClickedButton2d)
	ON_BN_CLICKED(IDC_BUTTON_2E, &CAboutDlg::OnBnClickedButton2e)
	ON_BN_CLICKED(IDC_BUTTON_2F, &CAboutDlg::OnBnClickedButton2f)
	ON_BN_CLICKED(IDC_BUTTON_2G, &CAboutDlg::OnBnClickedButton2g)
	ON_BN_CLICKED(IDC_BUTTON_2A, &CAboutDlg::OnBnClickedButton2a)
	ON_BN_CLICKED(IDC_BUTTON_2B, &CAboutDlg::OnBnClickedButton2b)
	ON_BN_CLICKED(IDC_BUTTON_2CH, &CAboutDlg::OnBnClickedButton2ch)
	ON_BN_CLICKED(IDC_BUTTON_2CS, &CAboutDlg::OnBnClickedButton2cs)
	ON_BN_CLICKED(IDC_BUTTON_2EF, &CAboutDlg::OnBnClickedButton2ef)
	ON_BN_CLICKED(IDC_BUTTON_2FS, &CAboutDlg::OnBnClickedButton2fs)
	ON_BN_CLICKED(IDC_BUTTON_2AF, &CAboutDlg::OnBnClickedButton2af)
	ON_BN_CLICKED(IDC_BUTTON_2Bb, &CAboutDlg::OnBnClickedButton2bf)
	ON_BN_CLICKED(IDC_BUTTON_3C, &CAboutDlg::OnBnClickedButton3c)
	ON_BN_CLICKED(IDC_BUTTON_3D, &CAboutDlg::OnBnClickedButton3d)
	ON_BN_CLICKED(IDC_BUTTON_3E, &CAboutDlg::OnBnClickedButton3e)
	ON_BN_CLICKED(IDC_BUTTON_3F, &CAboutDlg::OnBnClickedButton3f)
	ON_BN_CLICKED(IDC_BUTTON_3G, &CAboutDlg::OnBnClickedButton3g)
	ON_BN_CLICKED(IDC_BUTTON_3A, &CAboutDlg::OnBnClickedButton3a)
	ON_BN_CLICKED(IDC_BUTTON_3B, &CAboutDlg::OnBnClickedButton3b)
	ON_BN_CLICKED(IDC_BUTTON_3CH, &CAboutDlg::OnBnClickedButton3ch)
	ON_BN_CLICKED(IDC_BUTTON_3CS, &CAboutDlg::OnBnClickedButton3cs)
	ON_BN_CLICKED(IDC_BUTTON_3EF, &CAboutDlg::OnBnClickedButton3ef)
	ON_BN_CLICKED(IDC_BUTTON_3FS, &CAboutDlg::OnBnClickedButton3fs)
	ON_BN_CLICKED(IDC_BUTTON_3AF, &CAboutDlg::OnBnClickedButton3af)
	ON_BN_CLICKED(IDC_BUTTON_3BF, &CAboutDlg::OnBnClickedButton3bf)
	ON_BN_CLICKED(IDC_BUTTON_6C, &CAboutDlg::OnBnClickedButton6c)
	ON_BN_CLICKED(IDC_BUTTON_6D, &CAboutDlg::OnBnClickedButton6d)
	ON_BN_CLICKED(IDC_BUTTON_6E, &CAboutDlg::OnBnClickedButton6e)
	ON_BN_CLICKED(IDC_BUTTON_6F, &CAboutDlg::OnBnClickedButton6f)
	ON_BN_CLICKED(IDC_BUTTON_6G, &CAboutDlg::OnBnClickedButton6g)
	ON_BN_CLICKED(IDC_BUTTON_6A, &CAboutDlg::OnBnClickedButton6a)
	ON_BN_CLICKED(IDC_BUTTON_6B, &CAboutDlg::OnBnClickedButton6b)
	ON_BN_CLICKED(IDC_BUTTON_6CH, &CAboutDlg::OnBnClickedButton6ch)
	ON_BN_CLICKED(IDC_BUTTON_6CS, &CAboutDlg::OnBnClickedButton6cs)
	ON_BN_CLICKED(IDC_BUTTON_6EF, &CAboutDlg::OnBnClickedButton6ef)
	ON_BN_CLICKED(IDC_BUTTON_6FS, &CAboutDlg::OnBnClickedButton6fs)
	ON_BN_CLICKED(IDC_BUTTON_6AF, &CAboutDlg::OnBnClickedButton6af)
	ON_BN_CLICKED(IDC_BUTTON_6BF, &CAboutDlg::OnBnClickedButton6bf)
	ON_BN_CLICKED(IDC_BUTTON_7C, &CAboutDlg::OnBnClickedButton7c)
	ON_BN_CLICKED(IDC_BUTTON_7D, &CAboutDlg::OnBnClickedButton7d)
	ON_BN_CLICKED(IDC_BUTTON_7E, &CAboutDlg::OnBnClickedButton7e)
	ON_BN_CLICKED(IDC_BUTTON_7F, &CAboutDlg::OnBnClickedButton7f)
	ON_BN_CLICKED(IDC_BUTTON_7G, &CAboutDlg::OnBnClickedButton7g)
	ON_BN_CLICKED(IDC_BUTTON_7A, &CAboutDlg::OnBnClickedButton7a)
	ON_BN_CLICKED(IDC_BUTTON_7B, &CAboutDlg::OnBnClickedButton7b)
	ON_BN_CLICKED(IDC_BUTTON_7CH, &CAboutDlg::OnBnClickedButton7ch)
	ON_BN_CLICKED(IDC_BUTTON_7CS, &CAboutDlg::OnBnClickedButton7cs)
	ON_BN_CLICKED(IDC_BUTTON_7EF, &CAboutDlg::OnBnClickedButton7ef)
	ON_BN_CLICKED(IDC_BUTTON_7FS, &CAboutDlg::OnBnClickedButton7fs)
	ON_BN_CLICKED(IDC_BUTTON_7AF, &CAboutDlg::OnBnClickedButton7af)
	ON_BN_CLICKED(IDC_BUTTON_7BF, &CAboutDlg::OnBnClickedButton7bf)
	ON_BN_CLICKED(IDC_BUTTON_8C, &CAboutDlg::OnBnClickedButton8c)
	ON_BN_CLICKED(IDC_BUTTON_8D, &CAboutDlg::OnBnClickedButton8d)
	ON_BN_CLICKED(IDC_BUTTON_8E, &CAboutDlg::OnBnClickedButton8e)
	ON_BN_CLICKED(IDC_BUTTON_8F, &CAboutDlg::OnBnClickedButton8f)
	ON_BN_CLICKED(IDC_BUTTON_8G, &CAboutDlg::OnBnClickedButton8g)
	ON_BN_CLICKED(IDC_BUTTON_8A, &CAboutDlg::OnBnClickedButton8a)
	ON_BN_CLICKED(IDC_BUTTON_8B, &CAboutDlg::OnBnClickedButton8b)
	ON_BN_CLICKED(IDC_BUTTON_8CH, &CAboutDlg::OnBnClickedButton8ch)
	ON_BN_CLICKED(IDC_BUTTON_8CS, &CAboutDlg::OnBnClickedButton8cs)
	ON_BN_CLICKED(IDC_BUTTON_8EF, &CAboutDlg::OnBnClickedButton8ef)
	ON_BN_CLICKED(IDC_BUTTON_8FS, &CAboutDlg::OnBnClickedButton8fs)
	ON_BN_CLICKED(IDC_BUTTON_8AF, &CAboutDlg::OnBnClickedButton8af)
	ON_BN_CLICKED(IDC_BUTTON_8BF, &CAboutDlg::OnBnClickedButton8bf)
	END_MESSAGE_MAP()


// CJeopardyDlg dialog



///////////////////////////////////////////////////////////////////////////////

CJeopardyDlg::CJeopardyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJeopardyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nRoundNumber = 1;
	m_nCurrentScore_1 = 0;
	m_nCurrentScore_2 = 0;
	m_nCurrentScore_3 = 0;
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_1, m_csStatic1);
	DDX_Control(pDX, IDC_STATIC_2, m_csStatic2);
	DDX_Control(pDX, IDC_STATIC_3, m_csStatic3);
	DDX_Control(pDX, IDC_STATIC_4, m_csStatic4);
	DDX_Control(pDX, IDC_STATIC_5, m_csStatic5);
	DDX_Control(pDX, IDC_STATIC_6, m_csStatic6);
	DDX_Control(pDX, IDC_BUTTON1, m_CB1);
	DDX_Control(pDX, IDC_BUTTON2, m_CB2);
	DDX_Control(pDX, IDC_BUTTON3, m_CB3);
	DDX_Control(pDX, IDC_BUTTON4, m_CB4);
	DDX_Control(pDX, IDC_BUTTON5, m_CB5);
	DDX_Control(pDX, IDC_BUTTON6, m_CB6);
	DDX_Control(pDX, IDC_BUTTON7, m_CB7);
	DDX_Control(pDX, IDC_BUTTON8, m_CB8);
	DDX_Control(pDX, IDC_BUTTON9, m_CB9);
	DDX_Control(pDX, IDC_BUTTON10, m_CB10);
	DDX_Control(pDX, IDC_BUTTON11, m_CB11);
	DDX_Control(pDX, IDC_BUTTON12, m_CB12);
	DDX_Control(pDX, IDC_BUTTON13, m_CB13);
	DDX_Control(pDX, IDC_BUTTON14, m_CB14);
	DDX_Control(pDX, IDC_BUTTON15, m_CB15);
	DDX_Control(pDX, IDC_BUTTON16, m_CB16);
	DDX_Control(pDX, IDC_BUTTON17, m_CB17);
	DDX_Control(pDX, IDC_BUTTON18, m_CB18);
	DDX_Control(pDX, IDC_BUTTON19, m_CB19);
	DDX_Control(pDX, IDC_BUTTON20, m_CB20);
	DDX_Control(pDX, IDC_BUTTON21, m_CB21);
	DDX_Control(pDX, IDC_BUTTON22, m_CB22);
	DDX_Control(pDX, IDC_BUTTON23, m_CB23);
	DDX_Control(pDX, IDC_BUTTON24, m_CB24);
	DDX_Control(pDX, IDC_BUTTON25, m_CB25);
	DDX_Control(pDX, IDC_BUTTON26, m_CB26);
	DDX_Control(pDX, IDC_BUTTON27, m_CB27);
	DDX_Control(pDX, IDC_BUTTON28, m_CB28);
	DDX_Control(pDX, IDC_BUTTON29, m_CB29);
	DDX_Control(pDX, IDC_BUTTON30, m_CB30);
}
///////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CJeopardyDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CJeopardyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CJeopardyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CJeopardyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CJeopardyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CJeopardyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CJeopardyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CJeopardyDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CJeopardyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CJeopardyDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CJeopardyDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CJeopardyDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CJeopardyDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CJeopardyDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CJeopardyDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CJeopardyDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CJeopardyDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CJeopardyDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CJeopardyDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CJeopardyDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CJeopardyDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CJeopardyDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CJeopardyDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CJeopardyDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CJeopardyDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CJeopardyDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CJeopardyDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CJeopardyDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CJeopardyDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CJeopardyDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CJeopardyDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDOK, &CJeopardyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_ROUND_2, &CJeopardyDlg::OnBnClickedButtonRound2)
	ON_BN_CLICKED(IDC_BUTTON_ROUND_1, &CJeopardyDlg::OnBnClickedButtonRound1)
	ON_BN_CLICKED(IDC_BUTTON_TITLES, &CJeopardyDlg::OnBnClickedButtonTitles)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_THEME, &CJeopardyDlg::OnBnClickedButtonTheme)
	ON_BN_CLICKED(IDC_BUTTON_MUSIC_TEST, &CJeopardyDlg::OnBnClickedButtonMusicTest)
END_MESSAGE_MAP()


// CJeopardyDlg message handlers

BOOL CJeopardyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_num_buttons_available = 30;
	m_num_daily_doubles = 2;

	const CString sFont = L"Arial";


	m_csFont.CreateFontW(
		/* int nHeight,          */64, 
		/* int nWidth,           */0, 
		/* int nEscapement,      */0, 
		/* int nOrientation,     */0, 
		/* int nWeight,          */FW_NORMAL, 
		/* BYTE bItalic,         */FALSE, 
		/* BYTE bUnderline,      */FALSE, 
		/* BYTE cStrikeOut,      */FALSE, 
		/* BYTE nCharSet,        */ANSI_CHARSET, 
		/* BYTE nOutPrecision,   */OUT_DEFAULT_PRECIS, 
		/* BYTE nClipPrecision,  */CLIP_DEFAULT_PRECIS, 
		/* BYTE nQuality,        */DEFAULT_QUALITY, 
		/* BYTE nPitchAndFamily, */DEFAULT_PITCH, 
		/* LPCTSTR lpszFacename);*/sFont
		);
	m_csTitleFont.CreateFontW(
		/* int nHeight,          */32,
		/* int nWidth,           */0,
		/* int nEscapement,      */0,
		/* int nOrientation,     */0,
		/* int nWeight,          */FW_NORMAL,
		/* BYTE bItalic,         */FALSE,
		/* BYTE bUnderline,      */FALSE,
		/* BYTE cStrikeOut,      */FALSE,
		/* BYTE nCharSet,        */ANSI_CHARSET,
		/* BYTE nOutPrecision,   */OUT_DEFAULT_PRECIS,
		/* BYTE nClipPrecision,  */CLIP_DEFAULT_PRECIS,
		/* BYTE nQuality,        */DEFAULT_QUALITY,
		/* BYTE nPitchAndFamily, */DEFAULT_PITCH,
		/* LPCTSTR lpszFacename);*/sFont
	);
	m_csScoreFont.CreateFontW(
		/* int nHeight,          */28,
		/* int nWidth,           */0,
		/* int nEscapement,      */0,
		/* int nOrientation,     */0,
		/* int nWeight,          */FW_NORMAL,
		/* BYTE bItalic,         */FALSE,
		/* BYTE bUnderline,      */FALSE,
		/* BYTE cStrikeOut,      */FALSE,
		/* BYTE nCharSet,        */ANSI_CHARSET,
		/* BYTE nOutPrecision,   */OUT_DEFAULT_PRECIS,
		/* BYTE nClipPrecision,  */CLIP_DEFAULT_PRECIS,
		/* BYTE nQuality,        */DEFAULT_QUALITY,
		/* BYTE nPitchAndFamily, */DEFAULT_PITCH,
		/* LPCTSTR lpszFacename);*/sFont
	);
	m_color_white = RGB(255, 255, 255);
	m_color_black = RGB(0, 0, 0);

	m_color_red = RGB(255, 0, 0);
	m_color_orange = RGB(255, 165, 0);
	m_color_yellow = RGB(255, 255, 0);
	m_color_green = RGB(0, 255, 0);
	m_color_blue = RGB(0, 0, 255);
	m_color_indigo = RGB(75, 0, 130);
	m_color_violet = RGB(127, 0, 255);


	m_BackgroundMainColor = m_color_blue;
	m_ForegroundMainColor = m_color_white;
	m_BackgroundDialogColor = m_color_blue;
	m_ForegroundDialogColor = m_color_white;
	ReadColors();

	SECTION1 = _T("Section1");
	SECTION2 = _T("Section2");
	SECTION3 = _T("Section3");
	SECTION4 = _T("Section4");
	SECTION5 = _T("Section5");
	SECTION6 = _T("Section6");
	SECTION7 = _T("Section7");
	SECTION8 = _T("Section8");
	SECTION9 = _T("Section9");
	SECTION10 = _T("Section10");
	SECTION11 = _T("Section11");
	SECTION12 = _T("Section12");
	Q1 = _T("q1");
	A1 = _T("a1");
	V1 = _T("v1");
	Q2 = _T("q2");
	A2 = _T("a2");
	V2 = _T("v2");
	Q3 = _T("q3");
	A3 = _T("a3");
	V3 = _T("v3");
	Q4 = _T("q4");
	A4 = _T("a4");
	V4 = _T("v4");
	Q5 = _T("q5");
	A5 = _T("a5");
	V5 = _T("v5");

	TITLE    = _T("Title");
	BLANK_TITLE = _T("Blank Title");
	JEOPARDY_INI = _T(".\\jeopardy.ini");

	m_CB1.SetFont(&m_csFont,false);
	m_CB2.SetFont(&m_csFont,false);
	m_CB3.SetFont(&m_csFont,false);
	m_CB4.SetFont(&m_csFont,false);
	m_CB5.SetFont(&m_csFont,false);
	m_CB6.SetFont(&m_csFont,false);
	m_CB7.SetFont(&m_csFont,false);
	m_CB8.SetFont(&m_csFont,false);
	m_CB9.SetFont(&m_csFont,false);
	m_CB10.SetFont(&m_csFont,false);
	m_CB11.SetFont(&m_csFont,false);
	m_CB12.SetFont(&m_csFont,false);
	m_CB13.SetFont(&m_csFont,false);
	m_CB14.SetFont(&m_csFont,false);
	m_CB15.SetFont(&m_csFont,false);
	m_CB16.SetFont(&m_csFont,false);
	m_CB17.SetFont(&m_csFont,false);
	m_CB18.SetFont(&m_csFont,false);
	m_CB19.SetFont(&m_csFont,false);
	m_CB20.SetFont(&m_csFont,false);
	m_CB21.SetFont(&m_csFont,false);
	m_CB22.SetFont(&m_csFont,false);
	m_CB23.SetFont(&m_csFont,false);
	m_CB24.SetFont(&m_csFont,false);
	m_CB25.SetFont(&m_csFont,false);
	m_CB26.SetFont(&m_csFont,false);
	m_CB27.SetFont(&m_csFont,false);
	m_CB28.SetFont(&m_csFont,false);
	m_CB29.SetFont(&m_csFont,false);
	m_CB30.SetFont(&m_csFont,false);
	m_csStatic1.SetFont(&m_csTitleFont, false);
	m_csStatic2.SetFont(&m_csTitleFont, false);
	m_csStatic3.SetFont(&m_csTitleFont, false);
	m_csStatic4.SetFont(&m_csTitleFont, false);
	m_csStatic5.SetFont(&m_csTitleFont, false);
	m_csStatic6.SetFont(&m_csTitleFont, false);
	
	GetDlgItem(IDC_STATIC_SCORE_1)->SetFont(&m_csScoreFont, false);
	GetDlgItem(IDC_STATIC_SCORE_2)->SetFont(&m_csScoreFont, false);
	GetDlgItem(IDC_STATIC_SCORE_3)->SetFont(&m_csScoreFont, false);
	ReadData();

	m_Brush.CreateSolidBrush(m_BackgroundMainColor);
	CString csTitle1("Team 1 Score: ");
	CString csTitle2("Team 2 Score: ");
	CString csTitle3("Team 3 Score: ");
	ShowOutput(IDC_STATIC_SCORE_1, csTitle1, 0);
	ShowOutput(IDC_STATIC_SCORE_2, csTitle2, 0);
	ShowOutput(IDC_STATIC_SCORE_3, csTitle3, 0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
///////////////////////////////////////////////////////////////////////////////
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
///////////////////////////////////////////////////////////////////////////////
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CJeopardyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ReadColors()
{
	WCHAR csTemp[500];
	LPCWSTR csBlank;
	csBlank = _T("                                                                                                    ");
	TCHAR sAbsolutePathBuffer[2048] = _T("");

	CString csColor;
	if (GetFullPathName(TEXT(".\\jeopardy.ini"), sizeof(sAbsolutePathBuffer) / sizeof(TCHAR), sAbsolutePathBuffer, NULL))
	{
		m_ForegroundMainColor = m_color_white;
		m_BackgroundMainColor = m_color_blue;
		m_ForegroundDialogColor = m_color_white;
		m_BackgroundDialogColor = m_color_blue;
		GetPrivateProfileString(L"COLOR", L"foreground_main", csBlank, csTemp, 500, sAbsolutePathBuffer);
		csColor = csTemp;
		m_ForegroundMainColor = ColorPick(csColor);

		GetPrivateProfileString(L"COLOR", L"background_main", csBlank, csTemp, 500, sAbsolutePathBuffer);
		csColor = csTemp;
		m_BackgroundMainColor = ColorPick(csColor);

		GetPrivateProfileString(L"COLOR", L"foreground_dialog", csBlank, csTemp, 500, sAbsolutePathBuffer);
		csColor = csTemp;
		m_ForegroundDialogColor = ColorPick(csColor);

		GetPrivateProfileString(L"COLOR", L"background_dialog", csBlank, csTemp, 500, sAbsolutePathBuffer);
		csColor = csTemp;
		m_BackgroundDialogColor = ColorPick(csColor);
	}
}
///////////////////////////////////////////////////////////////////////////////
COLORREF CJeopardyDlg::ColorPick(CString csColor)
{
	COLORREF return_color = m_color_white;
	if (csColor == "white")
		return_color = m_color_white;
	else if (csColor == "black")
		return_color = m_color_black;
	else if (csColor == "red")
		return_color = m_color_red;
	else if (csColor == "orange")
		return_color = m_color_orange;
	else if (csColor == "yellow")
		return_color = m_color_yellow;
	else if (csColor == "green")
		return_color = m_color_green;
	else if (csColor == "blue")
		return_color = m_color_blue;
	else if (csColor == "indigo")
		return_color = m_color_indigo;
	else if (csColor == "violet")
		return_color = m_color_violet;
	else //custom color
	{
		int red_num = 0;
		int green_num = 0;
		int blue_num = 0;
		CString csComma(",");

		int first_comma = csColor.Find(csComma, 0);
		int second_comma = csColor.ReverseFind(',');
		red_num = min(max(atoi(CT2A(csColor.Left(first_comma))), 0), 255);
		green_num = min(max(atoi(CT2A(csColor.Mid(first_comma + 1, second_comma - first_comma - 1))), 0), 255);
		blue_num = min(max(atoi(CT2A(csColor.Right(csColor.GetAllocLength() - second_comma - 1))), 0), 255);

		return_color = RGB(red_num, green_num, blue_num);
	}

	return return_color;
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ReadData()
{
	WCHAR csTemp[500];
	LPCWSTR csBlank;
	CString csTemp2;

	csBlank = _T("                                                                                                    ");
	TCHAR sAbsolutePathBuffer[2048] = _T("");
	if (GetFullPathName(TEXT(".\\jeopardy.ini"), sizeof(sAbsolutePathBuffer)/sizeof(TCHAR), sAbsolutePathBuffer, NULL))
	{
		GetPrivateProfileString(SECTION1, TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle1 = csTemp;
		m_csStatic1.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION2,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle2 = csTemp;
		m_csStatic2.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION3,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle3 = csTemp;
		m_csStatic3.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION4,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle4 = csTemp;
		m_csStatic4.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION5,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle5 = csTemp;
		m_csStatic5.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION6,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle6 = csTemp;
		m_csStatic6.SetWindowTextW(csTemp);
		m_nRoundNumber = 1;
		GetPrivateProfileString(L"Mode", L"Theme", csBlank, csTemp, 500, sAbsolutePathBuffer);
		csDisplayMode = csTemp;
		if (csDisplayMode == "Christmas") //Christmas mode
		{
			SetButtonsRound1Christmas();
		}
		else
		{
			SetButtonsRound1();
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ReadData2()
{
	WCHAR csTemp[500];
	LPCWSTR csBlank;
	csBlank = _T("                                                                                                    ");
	TCHAR sAbsolutePathBuffer[2048] = _T("");
	if (GetFullPathName(TEXT(".\\jeopardy.ini"), sizeof(sAbsolutePathBuffer)/sizeof(TCHAR), sAbsolutePathBuffer, NULL))
	{
		GetPrivateProfileString(SECTION7, TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle1 = csTemp;
		m_csStatic1.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION8,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle2 = csTemp;
		m_csStatic2.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION9,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle3 = csTemp;
		m_csStatic3.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION10,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle4 = csTemp;
		m_csStatic4.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION11,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle5 = csTemp;
		m_csStatic5.SetWindowTextW(csTemp);
		GetPrivateProfileString(SECTION12,TITLE, csBlank, csTemp, 500, sAbsolutePathBuffer);
		m_csTitle6 = csTemp;
		m_csStatic6.SetWindowTextW(csTemp);
		m_nRoundNumber = 2;
		SetButtonsRound2();
	}
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton1()
{
	m_CB1.ShowWindow(FALSE);
	CString csTemp;
	m_CB1.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION1:SECTION7, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton2()
{
	m_CB2.ShowWindow(FALSE);
	CString csTemp;
	m_CB2.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION1:SECTION7, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton3()
{
	m_CB3.ShowWindow(FALSE);
	CString csTemp;
	m_CB3.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION1:SECTION7, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton4()
{
	m_CB4.ShowWindow(FALSE);
	CString csTemp;
	m_CB4.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION1:SECTION7, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton5()
{
	m_CB5.ShowWindow(FALSE);
	CString csTemp;
	m_CB5.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION1:SECTION7, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton6()
{
	m_CB6.ShowWindow(FALSE);
	CString csTemp;
	m_CB6.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION2:SECTION8, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton7()
{
	m_CB7.ShowWindow(FALSE);
	CString csTemp;
	m_CB7.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION2:SECTION8, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton8()
{
	m_CB8.ShowWindow(FALSE);
	CString csTemp;
	m_CB8.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION2:SECTION8, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton9()
{
	m_CB9.ShowWindow(FALSE);
	CString csTemp;
	m_CB9.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION2:SECTION8, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton10()
{
	m_CB10.ShowWindow(FALSE);
	CString csTemp;
	m_CB10.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION2:SECTION8, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton11()
{
	m_CB11.ShowWindow(FALSE);
	CString csTemp;
	m_CB11.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION3:SECTION9, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton12()
{
	m_CB12.ShowWindow(FALSE);
	CString csTemp;
	m_CB12.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION3:SECTION9, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton13()
{
	m_CB13.ShowWindow(FALSE);
	CString csTemp;
	m_CB13.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION3:SECTION9, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton14()
{
	m_CB14.ShowWindow(FALSE);
	CString csTemp;
	m_CB14.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION3:SECTION9, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton15()
{
	m_CB15.ShowWindow(FALSE);
	CString csTemp;
	m_CB15.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION3:SECTION9, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton16()
{
	m_CB16.ShowWindow(FALSE);
	CString csTemp;
	m_CB16.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION4:SECTION10, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton17()
{
	m_CB17.ShowWindow(FALSE);
	CString csTemp;
	m_CB17.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION4:SECTION10, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton18()
{
	m_CB18.ShowWindow(FALSE);
	CString csTemp;
	m_CB18.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION4:SECTION10, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton19()
{
	m_CB19.ShowWindow(FALSE);
	CString csTemp;
	m_CB19.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION4:SECTION10, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton20()
{
	m_CB20.ShowWindow(FALSE);
	CString csTemp;
	m_CB20.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION4:SECTION10, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton21()
{
	m_CB21.ShowWindow(FALSE);
	CString csTemp;
	m_CB21.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION5:SECTION11, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton22()
{
	m_CB22.ShowWindow(FALSE);
	CString csTemp;
	m_CB22.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION5:SECTION11, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton23()
{
	m_CB23.ShowWindow(FALSE);
	CString csTemp;
	m_CB23.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION5:SECTION11, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton24()
{
	m_CB24.ShowWindow(FALSE);
	CString csTemp;
	m_CB24.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION5:SECTION11, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton25()
{
	m_CB25.ShowWindow(FALSE);
	CString csTemp;
	m_CB25.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION5:SECTION11, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton26()
{
	m_CB26.ShowWindow(FALSE);
	CString csTemp;
	m_CB26.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(1) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION6:SECTION12, Q1, A1, V1, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton27()
{
	m_CB27.ShowWindow(FALSE);
	CString csTemp;
	m_CB27.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(2) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION6:SECTION12, Q2, A2, V2, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton28()
{
	m_CB28.ShowWindow(FALSE);
	CString csTemp;
	m_CB28.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(3) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION6:SECTION12, Q3, A3, V3, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton29()
{
	m_CB29.ShowWindow(FALSE);
	CString csTemp;
	m_CB29.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(4) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION6:SECTION12, Q4, A4, V4, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButton30()
{
	m_CB30.ShowWindow(FALSE);
	CString csTemp;
	m_CB30.GetWindowTextW(csTemp);
	int nScore = _ttoi(csTemp);
	nScore = nScore == 0 ? AdjustScore(5) : nScore;
	nScore = CheckDoubleJeopardy(nScore);
	LaunchQADialog((m_nRoundNumber == 1)?SECTION6:SECTION12, Q5, A5, V5, nScore);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::LaunchQADialog(CString csSection, CString csQuestion, CString csAnswer, CString csVideoPath, int nScore)
{
	WCHAR csTemp[500];
	LPCWSTR csBlank;
	csBlank = _T("                                                                                                    ");
	TCHAR sAbsolutePathBuffer[2048] = _T("");
	if (GetFullPathName(TEXT(".\\jeopardy.ini"), sizeof(sAbsolutePathBuffer)/sizeof(TCHAR), sAbsolutePathBuffer, NULL))
	{
		CQADialog sDialog(NULL, m_ForegroundDialogColor, m_BackgroundDialogColor);
		GetPrivateProfileString(csSection, csQuestion, csBlank, csTemp, 500, sAbsolutePathBuffer);
		sDialog.SetStaticQ(csTemp);
		GetPrivateProfileString(csSection, csAnswer, csBlank, csTemp, 500, sAbsolutePathBuffer);
		sDialog.SetStaticA(csTemp);
		GetPrivateProfileString(csSection, csVideoPath, csBlank, csTemp, 500, sAbsolutePathBuffer);
		sDialog.SetStaticV(csTemp);
		sDialog.DoModal();
		int answer_1 = sDialog.team_1_return_value;
		int answer_2 = sDialog.team_2_return_value;
		int answer_3 = sDialog.team_3_return_value;
		int nScore1 = nScore * (answer_1); //adjust running total based on button pressed
		int nScore2 = nScore * (answer_2); //adjust running total based on button pressed
		int nScore3 = nScore * (answer_3); //adjust running total based on button pressed
		m_nCurrentScore_1 = m_nCurrentScore_1 + nScore1;
		m_nCurrentScore_2 = m_nCurrentScore_2 + nScore2;
		m_nCurrentScore_3 = m_nCurrentScore_3 + nScore3;
		CString csTitle1("Team 1 Score: ");
		CString csTitle2("Team 2 Score: ");
		CString csTitle3("Team 3 Score: ");
		ShowOutput(IDC_STATIC_SCORE_1, csTitle1, m_nCurrentScore_1);
		ShowOutput(IDC_STATIC_SCORE_2, csTitle2, m_nCurrentScore_2);
		ShowOutput(IDC_STATIC_SCORE_3, csTitle3, m_nCurrentScore_3);
	}
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ShowOutput(int nStatic, CString strTitle, long long int nInput)
{
	wchar_t strBuffer[200];
	if (strTitle.GetLength() > 100)
	{
		strTitle = strTitle.Left(99);
	}

	ZeroMemory(&strBuffer, sizeof(strBuffer));
	if (nInput == -1)
	{
	}
	else
	{
		CString strNum;
		strNum.Format(_T("%d"), nInput);
		strTitle += strNum;
	}
	std::wstring strWideTitle(strTitle.GetBuffer());
	size_t nLength = strWideTitle.length() * 2;
	CopyMemory(strBuffer, strWideTitle.c_str(), nLength);
	GetDlgItem(nStatic)->SetWindowTextW(strBuffer);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedOk()
{
	ResetButtons();
	ResetScore();
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ResetScore()
{
	m_nCurrentScore_1 = 0;
	m_nCurrentScore_2 = 0;
	m_nCurrentScore_3 = 0;
	CString csTitle1("Team 1 Score: ");
	CString csTitle2("Team 2 Score: ");
	CString csTitle3("Team 3 Score: ");
	ShowOutput(IDC_STATIC_SCORE_1, csTitle1, 0);
	ShowOutput(IDC_STATIC_SCORE_2, csTitle2, 0);
	ShowOutput(IDC_STATIC_SCORE_3, csTitle3, 0);
	m_num_buttons_available = 30;
	m_num_daily_doubles = 2;
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::ResetButtons()
{
	m_CB1.ShowWindow(TRUE);
	m_CB2.ShowWindow(TRUE);
	m_CB3.ShowWindow(TRUE);
	m_CB4.ShowWindow(TRUE);
	m_CB5.ShowWindow(TRUE);
	m_CB6.ShowWindow(TRUE);
	m_CB7.ShowWindow(TRUE);
	m_CB8.ShowWindow(TRUE);
	m_CB9.ShowWindow(TRUE);
	m_CB10.ShowWindow(TRUE);
	m_CB11.ShowWindow(TRUE);
	m_CB12.ShowWindow(TRUE);
	m_CB13.ShowWindow(TRUE);
	m_CB14.ShowWindow(TRUE);
	m_CB15.ShowWindow(TRUE);
	m_CB16.ShowWindow(TRUE);
	m_CB17.ShowWindow(TRUE);
	m_CB18.ShowWindow(TRUE);
	m_CB19.ShowWindow(TRUE);
	m_CB20.ShowWindow(TRUE);
	m_CB21.ShowWindow(TRUE);
	m_CB22.ShowWindow(TRUE);
	m_CB23.ShowWindow(TRUE);
	m_CB24.ShowWindow(TRUE);
	m_CB25.ShowWindow(TRUE);
	m_CB26.ShowWindow(TRUE);
	m_CB27.ShowWindow(TRUE);
	m_CB28.ShowWindow(TRUE);
	m_CB29.ShowWindow(TRUE);
	m_CB30.ShowWindow(TRUE);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButtonRound2()
{
	ReadData2();
	ResetButtons();
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButtonRound1()
{
	ReadData();
	ResetButtons();
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButtonTitles()
{
	CQADialog sDialog(NULL, m_ForegroundMainColor, m_BackgroundMainColor);
	sDialog.m_bTitleMode = true;
	sDialog.SetStaticQ(m_csTitle1);
	sDialog.DoModal();
	sDialog.SetStaticQ(m_csTitle2);
	sDialog.DoModal();
	sDialog.SetStaticQ(m_csTitle3);
	sDialog.DoModal();
	sDialog.SetStaticQ(m_csTitle4);
	sDialog.DoModal();
	sDialog.SetStaticQ(m_csTitle5);
	sDialog.DoModal();
	sDialog.SetStaticQ(m_csTitle6);
	sDialog.DoModal();
}
///////////////////////////////////////////////////////////////////////////////
HBRUSH CJeopardyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(m_ForegroundMainColor);
		pDC->SetBkColor(m_BackgroundMainColor);
		break;
	default:
		break;
	}
	return (HBRUSH)m_Brush;
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonTest()
{
	PlayOdeToJoy();
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::PlayOdeToJoy()
{
	int nChoseInstrument = MidiCommands::MidiInstrumentChurchOrgan;
	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4E, nChoseInstrument);
	KeyDown(Note_4G, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4E, nChoseInstrument);
	KeyUp(Note_4G, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4FS, nChoseInstrument);
	KeyDown(Note_4A, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4FS, nChoseInstrument);
	KeyUp(Note_4A, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4FS, nChoseInstrument);
	KeyDown(Note_4A, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4FS, nChoseInstrument);
	KeyUp(Note_4A, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4E, nChoseInstrument);
	KeyDown(Note_4G, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4E, nChoseInstrument);
	KeyUp(Note_4G, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(375);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(125);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(500);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(250);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4E, nChoseInstrument);
	KeyDown(Note_4G, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4E, nChoseInstrument);
	KeyUp(Note_4G, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4FS, nChoseInstrument);
	KeyDown(Note_4A, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4FS, nChoseInstrument);
	KeyUp(Note_4A, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4FS, nChoseInstrument);
	KeyDown(Note_4A, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4FS, nChoseInstrument);
	KeyUp(Note_4A, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4E, nChoseInstrument);
	KeyDown(Note_4G, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4E, nChoseInstrument);
	KeyUp(Note_4G, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_4D, nChoseInstrument);
	KeyDown(Note_4FS, nChoseInstrument);
	Sleep(250);
	KeyUp(Note_4D, nChoseInstrument);
	KeyUp(Note_4FS, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4DF, nChoseInstrument);
	KeyDown(Note_4E, nChoseInstrument);
	Sleep(375);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4DF, nChoseInstrument);
	KeyUp(Note_4E, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(125);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(125);

	KeyDown(Note_3A, nChoseInstrument);
	KeyDown(Note_4D, nChoseInstrument);
	Sleep(500);
	KeyUp(Note_3A, nChoseInstrument);
	KeyUp(Note_4D, nChoseInstrument);
	Sleep(250);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::PlayThemeChord()
{
/*		MidiInstrumentAcousticGrandPiano = 0,
		MidiInstrumentBrightAcousticPiano = 1,
		MidiInstrumentElectricGrandPiano = 2,
		MidiInstrumentHonkyTonkPiano = 3,
		MidiInstrumentElectricPiano1 = 4,
		MidiInstrumentElectricPiano2 = 5,
		MidiInstrumentHarpsicord = 6,
		MidiInstrumentClavinet = 7,
		MidiInstrumentCelesta = 8,
		MidiInstrumentGlockenspiel = 9,
		MidiInstrumentMusicBox = 10,
		MidiInstrumentVibraphone = 11,
		MidiInstrumentMarimba = 12,
		MidiInstrumentXylophone = 13,
		MidiInstrumentTublarBells = 14,
		MidiInstrumentDulcimer = 15,
		MidiInstrumentDrawbarOrgan = 16,
		MidiInstrumentPercussiveOrgan = 17,
		MidiInstrumentRockOrgan = 18,
		MidiInstrumentChurchOrgan = 19,
		MidiInstrumentReedOrgan = 20,
		MidiInstrumentAccordion = 21,
		MidiInstrumentHarmonica = 22,
		MidiInstrumentTangoAccordion = 23,
		MidiInstrumentAcousticGuitarNylon = 24,
		MidiInstrumentAcousticGuitarSteel = 25,
		MidiInstrumentElectricGuitarJazz = 26,
		MidiInstrumentElectricGuitarClean = 27,
		MidiInstrumentElectricGuitarMuted = 28,
		MidiInstrumentOverdrivenGuitar = 29,
		MidiInstrumentDistortionGuitar = 30,
		MidiInstrumentGuitarHarmonics = 31,
		MidiInstrumentAcousticBass = 32,
		MidiInstrumentElectricBassFinger = 33,
		MidiInstrumentElectricBassPick = 34,
		MidiInstrumentFretlessBass = 35,
		MidiInstrumentSlapBass1 = 36,
		MidiInstrumentSlapBass2 = 37,
		MidiInstrumentSynthBass1 = 38,
		MidiInstrumentSynthBass2 = 39,
		MidiInstrumentViolin = 40,
		MidiInstrumentViola = 41,
		MidiInstrumentCello = 42,
		MidiInstrumentContrabass = 43,
		MidiInstrumentTremoloStrings = 44,
		MidiInstrumentPizzicatoStrings = 45,
		MidiInstrumentOrchestralHarp = 46,
		MidiInstrumentTimpani = 47,
		MidiInstrumentStringEnsemble1 = 48,
		MidiInstrumentStringEnsemble2 = 49,
		MidiInstrumentSynthString1 = 50,
		MidiInstrumentSynthStrings2 = 51,
		MidiInstrumentChoirAahs = 52,
		MidiInstrumentVoiceOohs = 53,
		MidiInstrumentSynthVoice = 54,
		MidiInstrumentOrchestraHit = 55,
		MidiInstrumentTrumpet = 56,
		MidiInstrumentTrombone = 57,
		MidiInstrumentTuba = 58,
		MidiInstrumentMutedTrumpet = 59,
		MidiInstrumentFrenchHorn = 60,
		MidiInstrumentBrassSection = 61,
		MidiInstrumentSynthBrass1 = 62,
		MidiInstrumentSynthBrass2 = 63,
		MidiInstrumentSopranoSax = 64,
		MidiInstrumentAltoSax = 65,
		MidiInstrumentTenorSax = 66,
		MidiInstrumentBaritoneSax = 67,
		MidiInstrumentOboe = 68,
		MidiInstrumentEnglishHorn = 69,
		MidiInstrumentBassoon = 70,
		MidiInstrumentClarinet = 71,
		MidiInstrumentPiccolo = 72,
		MidiInstrumentFlute = 73,
		MidiInstrumentRecorder = 74,
		MidiInstrumentPanFlute = 75,
		MidiInstrumentBlownBottle = 76,
		MidiInstrumentShakuhachi = 77,
		MidiInstrumentWhistle = 78,
		MidiInstrumentOcarina = 79,
		MidiInstrumentLead1Square = 80,
		MidiInstrumentLead2Sawtooth = 81,
		MidiInstrumentLead3Calliope = 82,
		MidiInstrumentLead4Chiff = 83,
		MidiInstrumentLead5Charang = 84,
		MidiInstrumentLead6Voice = 85,
		MidiInstrumentLead7Fifths = 86,
		MidiInstrumentLead8BassLead = 87,
		MidiInstrumentPad1NewAge = 88,
		MidiInstrumentPad2Warm = 89,
		MidiInstrumentPad3PolySynth = 90,
		MidiInstrumentPad4Choir = 91,
		MidiInstrumentPad5Bowed = 92,
		MidiInstrumentPad6Metallic = 93,
		MidiInstrumentPad7Halo = 94,
		MidiInstrumentPad8Sweep = 95,
		MidiInstrumentFX1Rain = 96,
		MidiInstrumentFX2Soundtrack = 97,
		MidiInstrumentFX3Crystal = 98,
		MidiInstrumentFX4Atmosphere = 99,
		MidiInstrumentFX5Brightness = 100,
		MidiInstrumentFX6Goblins = 101,
		MidiInstrumentFX7Echoes = 102,
		MidiInstrumentFX8SciFi = 103,
		MidiInstrumentSitar = 104,
		MidiInstrumentBanjo = 105,
		MidiInstrumentShamisen = 106,
		MidiInstrumentKoto = 107,
		MidiInstrumentKalimba = 108,
		MidiInstrumentBagPipe = 109,
		MidiInstrumentFiddle = 110,
		MidiInstrumentShanai = 111,
		MidiInstrumentTinkleBell = 112,
		MidiInstrumentAgogo = 113,
		MidiInstrumentSteelDrums = 114,
		MidiInstrumentWoodblock = 115,
		MidiInstrumentTaikoDrum = 116,
		MidiInstrumentMelodicTom = 117,
		MidiInstrumentSynthDrum = 118,
		MidiInstrumentReverseCymbal = 119,
		MidiInstrumentGutiarFretNoise = 120,
		MidiInstrumentBreathNoise = 121,
		MidiInstrumentSeashore = 122,
		MidiInstrumentBirdTweet = 123,
		MidiInstrumentTelephoneRing = 124,
		MidiInstrumentHelicopter = 125,
		MidiInstrumentApplause = 126,
		MidiInstrumentGunShot = 127*/

	int nChoseInstrument = MidiCommands::MidiInstrumentTrumpet;
	KeyDown(Note_4G, nChoseInstrument);	
	KeyDown(Note_4B, nChoseInstrument); 
	KeyDown(Note_5D, nChoseInstrument); 
	KeyDown(Note_5G, nChoseInstrument);		Sleep(375);
	KeyUp(Note_4G, nChoseInstrument);	
	KeyUp(Note_4B, nChoseInstrument);	
	KeyUp(Note_5D, nChoseInstrument);	
	KeyUp(Note_5G, nChoseInstrument);	Sleep(125);

	KeyDown(Note_5C, nChoseInstrument);	
	KeyDown(Note_5E,  nChoseInstrument); 
	KeyDown(Note_5G,  nChoseInstrument); 	
	KeyDown(Note_6C, nChoseInstrument);	Sleep(375);
	KeyUp(Note_5C, nChoseInstrument);	
	KeyUp(Note_5E,  nChoseInstrument);	
	KeyUp(Note_5G,  nChoseInstrument);
	KeyUp(Note_6C, nChoseInstrument);	Sleep(125);

	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4E, nChoseInstrument);	KeyDown(Note_4AF, nChoseInstrument); Sleep(125); KeyUp(Note_4E, nChoseInstrument);	KeyUp(Note_4AF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4F, nChoseInstrument);	KeyDown(Note_4A,  nChoseInstrument); Sleep(125); KeyUp(Note_4F, nChoseInstrument);	KeyUp(Note_4A,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5E, nChoseInstrument);	KeyDown(Note_5AF, nChoseInstrument); Sleep(125); KeyUp(Note_5E, nChoseInstrument);	KeyUp(Note_5AF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5D, nChoseInstrument);	KeyDown(Note_5FS, nChoseInstrument); Sleep(125); KeyUp(Note_5D, nChoseInstrument);	KeyUp(Note_5FS, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4B, nChoseInstrument);	KeyDown(Note_5EF, nChoseInstrument); Sleep(125); KeyUp(Note_4B, nChoseInstrument);	KeyUp(Note_5EF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4A, nChoseInstrument);	KeyDown(Note_5DF, nChoseInstrument); Sleep(125); KeyUp(Note_4A, nChoseInstrument);	KeyUp(Note_5DF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4E, nChoseInstrument);	KeyDown(Note_4AF, nChoseInstrument); Sleep(125); KeyUp(Note_4E, nChoseInstrument);	KeyUp(Note_4AF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4F, nChoseInstrument);	KeyDown(Note_4A,  nChoseInstrument); Sleep(125); KeyUp(Note_4F, nChoseInstrument);	KeyUp(Note_4A,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_5C, nChoseInstrument);	KeyDown(Note_5E,  nChoseInstrument); Sleep(125); KeyUp(Note_5C, nChoseInstrument);	KeyUp(Note_5E,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4A, nChoseInstrument);	KeyDown(Note_5DF, nChoseInstrument); Sleep(125); KeyUp(Note_4A, nChoseInstrument);	KeyUp(Note_5DF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4G, nChoseInstrument);	KeyDown(Note_4B,  nChoseInstrument); Sleep(125); KeyUp(Note_4G, nChoseInstrument);	KeyUp(Note_4B,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4F, nChoseInstrument);	KeyDown(Note_4A,  nChoseInstrument); Sleep(125); KeyUp(Note_4F, nChoseInstrument);	KeyUp(Note_4A,  nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4E, nChoseInstrument);	KeyDown(Note_4AF, nChoseInstrument); Sleep(125); KeyUp(Note_4E, nChoseInstrument);	KeyUp(Note_4AF, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4D, nChoseInstrument);	KeyDown(Note_4FS, nChoseInstrument); Sleep(125); KeyUp(Note_4D, nChoseInstrument);	KeyUp(Note_4FS, nChoseInstrument);	Sleep(125);
	//KeyDown(Note_4C, nChoseInstrument);	KeyDown(Note_4E,  nChoseInstrument); Sleep(125); KeyUp(Note_4C, nChoseInstrument);	KeyUp(Note_4E,  nChoseInstrument);	Sleep(125);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::PlayMarineCorp()
{
	//4C,250,19,4E,250,19,4G,500,19,4G,500,19,4G,500,19,4G,500,19,4G,750,19,5C,250,19,4G,500,19,4E,250,19,4F,250,19,4G,500,19,4G,500,19,4F,250,19,4D,600,19,4C,1000,19
	int nChoseInstrument = MidiCommands::MidiInstrumentTrumpet;
	KeyDown(Note_4C, nChoseInstrument); KeyDown(Note_4E, nChoseInstrument); KeyDown(Note_4G, nChoseInstrument);  Sleep(125);	
	KeyUp(Note_4C, nChoseInstrument);   KeyUp(Note_4E, nChoseInstrument);   KeyUp(Note_4G, nChoseInstrument);  	 Sleep(125);

	KeyDown(Note_4E, nChoseInstrument); /*KeyDown(Note_4AF, nChoseInstrument);KeyDown(Note_4B, nChoseInstrument);*/  Sleep(125);
	KeyUp(Note_4E, nChoseInstrument);   /*KeyUp(Note_4AF, nChoseInstrument);  KeyUp(Note_4B, nChoseInstrument);*/	 Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument);*/   Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(250);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument);*/   Sleep(125);

	KeyDown(Note_5C, nChoseInstrument); /*KeyDown(Note_5E, nChoseInstrument); KeyDown(Note_5G, nChoseInstrument);*/  Sleep(125);
	KeyUp(Note_5C, nChoseInstrument);   /*KeyUp(Note_5E, nChoseInstrument);   KeyUp(Note_5G, nChoseInstrument);*/    Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument);*/   Sleep(125);

	KeyDown(Note_4C, nChoseInstrument); /*KeyDown(Note_4E, nChoseInstrument); KeyDown(Note_4G, nChoseInstrument);*/  Sleep(125);
	KeyUp(Note_4C, nChoseInstrument);   /*KeyUp(Note_4E, nChoseInstrument);   KeyUp(Note_4G, nChoseInstrument);*/    Sleep(125);

	KeyDown(Note_4E, nChoseInstrument); /*KeyDown(Note_4AF, nChoseInstrument); KeyDown(Note_4B, nChoseInstrument);*/ Sleep(125);
	KeyUp(Note_4E, nChoseInstrument);   /*KeyUp(Note_4AF, nChoseInstrument);   KeyUp(Note_4B, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(250);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4G, nChoseInstrument); /*KeyDown(Note_4B, nChoseInstrument); KeyDown(Note_5DF, nChoseInstrument);*/ Sleep(250);
	KeyUp(Note_4G, nChoseInstrument);   /*KeyUp(Note_4B, nChoseInstrument);   KeyUp(Note_5DF, nChoseInstrument); */  Sleep(125);

	KeyDown(Note_4F, nChoseInstrument); /*KeyDown(Note_4A, nChoseInstrument); KeyDown(Note_5C, nChoseInstrument);*/  Sleep(125);
	KeyUp(Note_4F, nChoseInstrument);   /*KeyUp(Note_4A, nChoseInstrument);   KeyUp(Note_5C, nChoseInstrument);*/    Sleep(125);

	KeyDown(Note_4D, nChoseInstrument); /*KeyDown(Note_4FS, nChoseInstrument); KeyDown(Note_4BF, nChoseInstrument);*/Sleep(125);
	KeyUp(Note_4D, nChoseInstrument);   /*KeyUp(Note_4FS, nChoseInstrument);   KeyUp(Note_4BF, nChoseInstrument);*/  Sleep(125);

	KeyDown(Note_4C, nChoseInstrument); /*KeyDown(Note_4E, nChoseInstrument); KeyDown(Note_4G, nChoseInstrument); KeyDown(Note_5C, nChoseInstrument); */ Sleep(750);
	KeyUp(Note_4C, nChoseInstrument);   /*KeyUp(Note_4E, nChoseInstrument);   KeyUp(Note_4G, nChoseInstrument);   KeyUp(Note_5C, nChoseInstrument);*/    Sleep(125);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::PlayNote(int note, int duration, int instrument)
{
	// Send out a series of MIDI messages.
	// Program change: 192, 5
	message.push_back(MidiCommands::MidiProgramChange);
	message.push_back(instrument);
	midiout.sendMessage(&message);

	// Control Change: 176, 7, 100 (volume)
	message[0] = MidiCommands::MidiVolumeSet;
	message[1] = 7;
	message.push_back(100);
	midiout.sendMessage(&message);

	// Note On: 144, 64, 90
	message[0] = MidiCommands::MidiNoteStart;
	message[1] = note;
	message[2] = MidiCommands::MidiNoteVelocity;
	midiout.sendMessage(&message);

	SLEEP(duration);

	// Note Off: 128, 64, 40
	message[0] = MidiCommands::MidiNoteStop;
	message[1] = note;
	message[2] = MidiCommands::MidiNoteVelocity;
	midiout.sendMessage(&message);
	message.clear();
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::KeyDown(int note, int instrument)
{
	// Send out a series of MIDI messages.
	// Program change: 192, 5
	message.push_back(MidiCommands::MidiProgramChange);
	message.push_back(instrument);
	midiout.sendMessage(&message);

	// Control Change: 176, 7, 100 (volume)
	message[0] = MidiCommands::MidiVolumeSet;
	message[1] = 7;
	message.push_back(100);
	midiout.sendMessage(&message);

	// Note On: 144, 64, 90
	message[0] = MidiCommands::MidiNoteStart;
	message[1] = note;
	message[2] = MidiCommands::MidiNoteVelocity;
	midiout.sendMessage(&message);

	message.clear();
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::KeyUp(int note, int instrument)
{
	// Send out a series of MIDI messages.
	// Program change: 192, 5
	message.push_back(MidiCommands::MidiProgramChange);
	message.push_back(instrument);
	midiout.sendMessage(&message);

	// Control Change: 176, 7, 100 (volume)
	message[0] = MidiCommands::MidiVolumeSet;
	message[1] = 7;
	message.push_back(100);
	midiout.sendMessage(&message);

	// Note Off: 128, 64, 40
	message[0] = MidiCommands::MidiNoteStop;
	message[1] = note;
	message[2] = MidiCommands::MidiNoteVelocity;
	midiout.sendMessage(&message);
	message.clear();
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonC()
{
	PlayNote(Notes::Note_4C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonD()
{
	PlayNote(Notes::Note_4D, 500, 5); 
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonE()
{
	PlayNote(Notes::Note_4E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonF()
{
	PlayNote(Notes::Note_4F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonG()
{
	PlayNote(Notes::Note_4G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonA()
{
	PlayNote(Notes::Note_4A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonB()
{
	PlayNote(Notes::Note_4B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonCHigh()
{
	PlayNote(Notes::Note_5C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonCSharp()
{
	PlayNote(Notes::Note_4DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonEFlat()
{
	PlayNote(Notes::Note_4EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonFSharp()
{
	PlayNote(Notes::Note_4FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonAFlat()
{
	PlayNote(Notes::Note_4AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonBFlat()
{
	PlayNote(Notes::Note_4BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
int CAboutDlg::GetIntFromCString(CString csInput)
{
	int nReturn = std::stoi({csInput.GetString(), static_cast<size_t>(csInput.GetLength())});
	return nReturn;
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButtonTheme()
{
	PlaySound(L"C:\\dev\\Jeopardy_deploy\\media\\Jeopardy_Main.wav", NULL, SND_APPLICATION);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::RunINITest2()
{
	PlayMusicList(NOTELIST);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::PlayMusicList(CString csMusicList)
{
	CString csNote;
	CString csDuration;
	CString csInstrument;
	int nIndex = -1;
	CString csNotesList;
	WCHAR csTemp[1000];
	for (int nIndex = 0; nIndex < 500; nIndex++)
	{
		csTemp[nIndex] = 0;
	}
	LPCWSTR csBlank;
	csBlank = _T("                                                                                                    ");
	TCHAR sAbsolutePathBuffer[2048] = _T("");
	std::vector<std::string> vecNoteList;
	std::vector<int> vecNoteDuration;
	std::vector<int> vecInstrumentList;
	int nDuration;
	int nInstrument;
	if (GetFullPathName(TEXT("jeopardy.ini"), sizeof(sAbsolutePathBuffer) / sizeof(TCHAR), sAbsolutePathBuffer, NULL))
	{
		GetPrivateProfileString(MUSIC, (LPCWSTR)(const char*)csMusicList.GetBuffer(), csBlank, csTemp, 1000, sAbsolutePathBuffer);
		csNotesList = csTemp;
		while (csNotesList.GetLength() > 0)
		{
			nIndex = csNotesList.Find(',');
			if (nIndex > -1)
			{				
				csNote = csNotesList.Left(nIndex);
				std::string strNote = CT2A(csNote.GetString());
				vecNoteList.push_back(strNote);
				csNotesList = csNotesList.Right(csNotesList.GetLength() - nIndex - 1);
				nIndex = csNotesList.Find(',');
				if (nIndex == -1)
				{
					nIndex = csNotesList.GetLength();
				}
				if (nIndex > -1)
				{
					csDuration = csNotesList.Left(nIndex);
					nDuration = GetIntFromCString(csDuration);
					vecNoteDuration.push_back(nDuration);
					csNotesList = csNotesList.Right(csNotesList.GetLength() - nIndex - 1);
				}
				nIndex = csNotesList.Find(',');
				if (nIndex == -1)
				{
					nIndex = csNotesList.GetLength();
				}
				if (nIndex > -1)
				{
					csInstrument = csNotesList.Left(nIndex);
					nInstrument = GetIntFromCString(csInstrument);
					vecInstrumentList.push_back(nInstrument);
					csNotesList = csNotesList.Right(csNotesList.GetLength() - nIndex - 1);
				}

			}
		}
		int nVectorSize = vecNoteList.size();
		for (nIndex = 0; nIndex < nVectorSize; nIndex++)
		{ //Todo: Expand to cover all 88 keys of a keyboard
			if (vecNoteList[nIndex]		 == "1C")  { PlayNote(Notes::Note_1C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1DF") { PlayNote(Notes::Note_1DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1D")  { PlayNote(Notes::Note_1D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1EF") { PlayNote(Notes::Note_1EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1E")  { PlayNote(Notes::Note_1E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1F")  { PlayNote(Notes::Note_1F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1FS") { PlayNote(Notes::Note_1FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1G")  { PlayNote(Notes::Note_1G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1AF") { PlayNote(Notes::Note_1AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1A")  { PlayNote(Notes::Note_1A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1BF") { PlayNote(Notes::Note_1BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "1B")  { PlayNote(Notes::Note_1B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2C")  { PlayNote(Notes::Note_2C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2DF") { PlayNote(Notes::Note_2DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2D")  { PlayNote(Notes::Note_2D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2EF") { PlayNote(Notes::Note_2EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2E")  { PlayNote(Notes::Note_2E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2F")  { PlayNote(Notes::Note_2F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2FS") { PlayNote(Notes::Note_2FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2G")  { PlayNote(Notes::Note_2G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2AF") { PlayNote(Notes::Note_2AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2A")  { PlayNote(Notes::Note_2A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2BF") { PlayNote(Notes::Note_2BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "2B")  { PlayNote(Notes::Note_2B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3C")  { PlayNote(Notes::Note_3C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3DF") { PlayNote(Notes::Note_3DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3D")  { PlayNote(Notes::Note_3D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3EF") { PlayNote(Notes::Note_3EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3E")  { PlayNote(Notes::Note_3E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3F")  { PlayNote(Notes::Note_3F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3FS") { PlayNote(Notes::Note_3FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3G")  { PlayNote(Notes::Note_3G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3AF") { PlayNote(Notes::Note_3AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3A")  { PlayNote(Notes::Note_3A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3BF") { PlayNote(Notes::Note_3BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "3B")  { PlayNote(Notes::Note_3B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4C")  { PlayNote(Notes::Note_4C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4DF") { PlayNote(Notes::Note_4DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4D")  { PlayNote(Notes::Note_4D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4EF") { PlayNote(Notes::Note_4DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4E")  { PlayNote(Notes::Note_4E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4F")  { PlayNote(Notes::Note_4F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4FS") { PlayNote(Notes::Note_4FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4G")  { PlayNote(Notes::Note_4G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4AF") { PlayNote(Notes::Note_4AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4A")  { PlayNote(Notes::Note_4A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4BF") { PlayNote(Notes::Note_4BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "4B")  { PlayNote(Notes::Note_4B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5C")  { PlayNote(Notes::Note_5C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5CS") { PlayNote(Notes::Note_5DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5D")  { PlayNote(Notes::Note_5D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5EF") { PlayNote(Notes::Note_5EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5E")  { PlayNote(Notes::Note_5E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5F")  { PlayNote(Notes::Note_5F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5FS") { PlayNote(Notes::Note_5FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5G")  { PlayNote(Notes::Note_5G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5AF") { PlayNote(Notes::Note_5AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
            else if (vecNoteList[nIndex] == "5A")  { PlayNote(Notes::Note_5A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5BF") { PlayNote(Notes::Note_5BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "5B")  { PlayNote(Notes::Note_5B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6C")  { PlayNote(Notes::Note_6C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6DF") { PlayNote(Notes::Note_6DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6D")  { PlayNote(Notes::Note_6D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6EF") { PlayNote(Notes::Note_6EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6E")  { PlayNote(Notes::Note_6E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6F")  { PlayNote(Notes::Note_6F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6FS") { PlayNote(Notes::Note_6FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6G")  { PlayNote(Notes::Note_6G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6AF") { PlayNote(Notes::Note_6AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6A")  { PlayNote(Notes::Note_6A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6BF") { PlayNote(Notes::Note_6BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "6B")  { PlayNote(Notes::Note_6B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7C")  { PlayNote(Notes::Note_7C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7DF") { PlayNote(Notes::Note_7DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7D")  { PlayNote(Notes::Note_7D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7EF") { PlayNote(Notes::Note_7EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7E")  { PlayNote(Notes::Note_7E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7F")  { PlayNote(Notes::Note_7F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7FS") { PlayNote(Notes::Note_7FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }			
			else if (vecNoteList[nIndex] == "7G")  { PlayNote(Notes::Note_7G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7AF") { PlayNote(Notes::Note_7AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7A")  { PlayNote(Notes::Note_7A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7BF") { PlayNote(Notes::Note_7B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "7B")  { PlayNote(Notes::Note_7BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8C")  { PlayNote(Notes::Note_8C,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8DF") { PlayNote(Notes::Note_8DF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8D")  { PlayNote(Notes::Note_8D,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8EF") { PlayNote(Notes::Note_8EF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8E")  { PlayNote(Notes::Note_8E,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8F")  { PlayNote(Notes::Note_8F,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8FS") { PlayNote(Notes::Note_8FS, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8G")  { PlayNote(Notes::Note_8G,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8AF") { PlayNote(Notes::Note_8AF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8A")  { PlayNote(Notes::Note_8A,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8BF") { PlayNote(Notes::Note_8BF, vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else if (vecNoteList[nIndex] == "8B")  { PlayNote(Notes::Note_8B,  vecNoteDuration[nIndex], vecInstrumentList[nIndex]); }
			else
			{
				int i = 0; //no valid note setting was found
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButtonTheme()
{
	CAboutDlg dlgAbout;
	dlgAbout.OnBnClickedButtonTheme();
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5c()
{
	PlayNote(Notes::Note_5C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5d()
{
	PlayNote(Notes::Note_5D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5e()
{
	PlayNote(Notes::Note_5E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5f()
{
	PlayNote(Notes::Note_5F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5g()
{
	PlayNote(Notes::Note_5G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5a()
{
	PlayNote(Notes::Note_5A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5b()
{
	PlayNote(Notes::Note_5B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5ch()
{
	PlayNote(Notes::Note_6C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5cs()
{
	PlayNote(Notes::Note_5DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5ef()
{
	PlayNote(Notes::Note_5EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5fs()
{
	PlayNote(Notes::Note_5FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5af()
{
	PlayNote(Notes::Note_5AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton5bf()
{
	PlayNote(Notes::Note_5BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1c()
{
	PlayNote(Notes::Note_1C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1d()
{
	PlayNote(Notes::Note_1D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1e()
{
	PlayNote(Notes::Note_1E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1f()
{
	PlayNote(Notes::Note_1F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1g()
{
	PlayNote(Notes::Note_1G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1a()
{
	PlayNote(Notes::Note_1A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1b()
{
	PlayNote(Notes::Note_1B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1ch()
{
	PlayNote(Notes::Note_2C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1cs()
{
	PlayNote(Notes::Note_1DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1ef()
{
	PlayNote(Notes::Note_1EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1fs()
{
	PlayNote(Notes::Note_1FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1af()
{
	PlayNote(Notes::Note_1AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton1bf()
{
	PlayNote(Notes::Note_1BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2c()
{
	PlayNote(Notes::Note_2C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2d()
{
	PlayNote(Notes::Note_2D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2e()
{
	PlayNote(Notes::Note_2E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2f()
{
	PlayNote(Notes::Note_2F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2g()
{
	PlayNote(Notes::Note_2G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2a()
{
	PlayNote(Notes::Note_2A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2b()
{
	PlayNote(Notes::Note_2B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2ch()
{
	PlayNote(Notes::Note_3C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2cs()
{
	PlayNote(Notes::Note_2DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2ef()
{
	PlayNote(Notes::Note_2EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2fs()
{
	PlayNote(Notes::Note_2FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2af()
{
	PlayNote(Notes::Note_2AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton2bf()
{
	PlayNote(Notes::Note_2BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3c()
{
	PlayNote(Notes::Note_3C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3d()
{
	PlayNote(Notes::Note_3D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3e()
{
	PlayNote(Notes::Note_3E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3f()
{
	PlayNote(Notes::Note_3F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3g()
{
	PlayNote(Notes::Note_3G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3a()
{
	PlayNote(Notes::Note_3A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3b()
{
	PlayNote(Notes::Note_3B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3ch()
{
	PlayNote(Notes::Note_4C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3cs()
{
	PlayNote(Notes::Note_3DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3ef()
{
	PlayNote(Notes::Note_3EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3fs()
{
	PlayNote(Notes::Note_3FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3af()
{
	PlayNote(Notes::Note_3AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton3bf()
{
	PlayNote(Notes::Note_3BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6c()
{
	PlayNote(Notes::Note_6C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6d()
{
	PlayNote(Notes::Note_6D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6e()
{
	PlayNote(Notes::Note_6E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6f()
{
	PlayNote(Notes::Note_6F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6g()
{
	PlayNote(Notes::Note_6G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6a()
{
	PlayNote(Notes::Note_6A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6b()
{
	PlayNote(Notes::Note_6B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6ch()
{
	PlayNote(Notes::Note_7C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6cs()
{
	PlayNote(Notes::Note_6DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6ef()
{
	PlayNote(Notes::Note_6EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6fs()
{
	PlayNote(Notes::Note_6FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6af()
{
	PlayNote(Notes::Note_6AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton6bf()
{
	PlayNote(Notes::Note_6BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7c()
{
	PlayNote(Notes::Note_7C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7d()
{
	PlayNote(Notes::Note_7D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7e()
{
	PlayNote(Notes::Note_7E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7f()
{
	PlayNote(Notes::Note_7F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7g()
{
	PlayNote(Notes::Note_7G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7a()
{
	PlayNote(Notes::Note_7A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7b()
{
	PlayNote(Notes::Note_7B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7ch()
{
	PlayNote(Notes::Note_8C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7cs()
{
	PlayNote(Notes::Note_7DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7ef()
{
	PlayNote(Notes::Note_7EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7fs()
{
	PlayNote(Notes::Note_7FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7af()
{
	PlayNote(Notes::Note_7AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton7bf()
{
	PlayNote(Notes::Note_7BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8c()
{
	PlayNote(Notes::Note_8C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8d()
{
	PlayNote(Notes::Note_8D, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8e()
{
	PlayNote(Notes::Note_8E, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8f()
{
	PlayNote(Notes::Note_8F, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8g()
{
	PlayNote(Notes::Note_8G, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8a()
{
	PlayNote(Notes::Note_8A, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8b()
{
	PlayNote(Notes::Note_8B, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8ch()
{
	PlayNote(Notes::Note_9C, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8cs()
{
	PlayNote(Notes::Note_8DF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8ef()
{
	PlayNote(Notes::Note_8EF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8fs()
{
	PlayNote(Notes::Note_8FS, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8af()
{
	PlayNote(Notes::Note_8AF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CAboutDlg::OnBnClickedButton8bf()
{
	PlayNote(Notes::Note_8BF, 500, 5);
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::OnBnClickedButtonMusicTest()
{
	CAboutDlg dlgAbout;
	dlgAbout.OnBnClickedButtonTest();
}
///////////////////////////////////////////////////////////////////////////////
int CJeopardyDlg::CheckDoubleJeopardy(int nScore)
{
	if (m_num_daily_doubles > 0)
	{
		srand((unsigned int)(time(0)));
		double percent_chance = 100.0;
		if (m_num_buttons_available > 0)
		{
			percent_chance = (double)(1.0 / (double)(m_num_buttons_available)) * 100.0;
		}
		double dice_roll = (double)(rand() % 100 + 1);
		if ((dice_roll <= percent_chance) || //we've got Daily Double
		    ((m_num_daily_doubles == 2) && (m_num_buttons_available == 2)) //mandatory
		   )
		{
			m_num_daily_doubles = m_num_daily_doubles - 1;
			DailyDouble dlgDailyDouble(NULL, m_ForegroundDialogColor, m_BackgroundDialogColor);
			dlgDailyDouble.m_csAmount.Format(L"%d", nScore);
			dlgDailyDouble.DoModal();
			CString csScore = dlgDailyDouble.m_csAmount;
			nScore = _ttoi(csScore);
		}
		m_num_buttons_available = m_num_buttons_available - 1;
	}
	return nScore;
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::SetButtonsRound1()
{
	m_CB1.SetWindowTextW(_T("100"));
	m_CB2.SetWindowTextW(_T("200"));
	m_CB3.SetWindowTextW(_T("300"));
	m_CB4.SetWindowTextW(_T("400"));
	m_CB5.SetWindowTextW(_T("500"));
	m_CB6.SetWindowTextW(_T("100"));
	m_CB7.SetWindowTextW(_T("200"));
	m_CB8.SetWindowTextW(_T("300"));
	m_CB9.SetWindowTextW(_T("400"));
	m_CB10.SetWindowTextW(_T("500"));
	m_CB11.SetWindowTextW(_T("100"));
	m_CB12.SetWindowTextW(_T("200"));
	m_CB13.SetWindowTextW(_T("300"));
	m_CB14.SetWindowTextW(_T("400"));
	m_CB15.SetWindowTextW(_T("500"));
	m_CB16.SetWindowTextW(_T("100"));
	m_CB17.SetWindowTextW(_T("200"));
	m_CB18.SetWindowTextW(_T("300"));
	m_CB19.SetWindowTextW(_T("400"));
	m_CB20.SetWindowTextW(_T("500"));
	m_CB21.SetWindowTextW(_T("100"));
	m_CB22.SetWindowTextW(_T("200"));
	m_CB23.SetWindowTextW(_T("300"));
	m_CB24.SetWindowTextW(_T("400"));
	m_CB25.SetWindowTextW(_T("500"));
	m_CB26.SetWindowTextW(_T("100"));
	m_CB27.SetWindowTextW(_T("200"));
	m_CB28.SetWindowTextW(_T("300"));
	m_CB29.SetWindowTextW(_T("400"));
	m_CB30.SetWindowTextW(_T("500"));
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::SetButtonsRound2()
{
	m_CB1.SetWindowTextW(_T("200"));
	m_CB2.SetWindowTextW(_T("400"));
	m_CB3.SetWindowTextW(_T("600"));
	m_CB4.SetWindowTextW(_T("800"));
	m_CB5.SetWindowTextW(_T("1000"));
	m_CB6.SetWindowTextW(_T("200"));
	m_CB7.SetWindowTextW(_T("400"));
	m_CB8.SetWindowTextW(_T("600"));
	m_CB9.SetWindowTextW(_T("800"));
	m_CB10.SetWindowTextW(_T("1000"));
	m_CB11.SetWindowTextW(_T("200"));
	m_CB12.SetWindowTextW(_T("400"));
	m_CB13.SetWindowTextW(_T("600"));
	m_CB14.SetWindowTextW(_T("800"));
	m_CB15.SetWindowTextW(_T("1000"));
	m_CB16.SetWindowTextW(_T("200"));
	m_CB17.SetWindowTextW(_T("400"));
	m_CB18.SetWindowTextW(_T("600"));
	m_CB19.SetWindowTextW(_T("800"));
	m_CB20.SetWindowTextW(_T("1000"));
	m_CB21.SetWindowTextW(_T("200"));
	m_CB22.SetWindowTextW(_T("400"));
	m_CB23.SetWindowTextW(_T("600"));
	m_CB24.SetWindowTextW(_T("800"));
	m_CB25.SetWindowTextW(_T("1000"));
	m_CB26.SetWindowTextW(_T("200"));
	m_CB27.SetWindowTextW(_T("400"));
	m_CB28.SetWindowTextW(_T("600"));
	m_CB29.SetWindowTextW(_T("800"));
	m_CB30.SetWindowTextW(_T("1000"));
}
///////////////////////////////////////////////////////////////////////////////
void CJeopardyDlg::SetButtonsRound1Christmas()
{
	CBitmap bitmap1;
	CBitmap bitmap2;
	CBitmap bitmap3;
	CBitmap bitmap4;
	CBitmap bitmap5;
	bitmap1.LoadBitmapW(IDB_BIT100);
	bitmap2.LoadBitmapW(IDB_BIT200);
	bitmap3.LoadBitmapW(IDB_BIT300);
	bitmap4.LoadBitmapW(IDB_BIT400);
	bitmap5.LoadBitmapW(IDB_BIT500);
	HBITMAP hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
	HBITMAP hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();
	HBITMAP hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();
	HBITMAP hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();
	HBITMAP hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();

	m_CB1.ModifyStyle(0, BS_BITMAP);
	m_CB1.SetBitmap(hBmp1);
	m_CB6.ModifyStyle(0, BS_BITMAP);
	m_CB6.SetBitmap(hBmp1);
	m_CB11.ModifyStyle(0, BS_BITMAP);
	m_CB11.SetBitmap(hBmp1);
	m_CB16.ModifyStyle(0, BS_BITMAP);
	m_CB16.SetBitmap(hBmp1);
	m_CB21.ModifyStyle(0, BS_BITMAP);
	m_CB21.SetBitmap(hBmp1);
	m_CB26.ModifyStyle(0, BS_BITMAP);
	m_CB26.SetBitmap(hBmp1);

	m_CB2.ModifyStyle(0, BS_BITMAP);
	m_CB2.SetBitmap(hBmp2);
	m_CB7.ModifyStyle(0, BS_BITMAP);
	m_CB7.SetBitmap(hBmp2);
	m_CB12.ModifyStyle(0, BS_BITMAP);
	m_CB12.SetBitmap(hBmp2);
	m_CB17.ModifyStyle(0, BS_BITMAP);
	m_CB17.SetBitmap(hBmp2);
	m_CB22.ModifyStyle(0, BS_BITMAP);
	m_CB22.SetBitmap(hBmp2);
	m_CB27.ModifyStyle(0, BS_BITMAP);
	m_CB27.SetBitmap(hBmp2);

	m_CB3.ModifyStyle(0, BS_BITMAP);
	m_CB3.SetBitmap(hBmp3);
	m_CB8.ModifyStyle(0, BS_BITMAP);
	m_CB8.SetBitmap(hBmp3);
	m_CB13.ModifyStyle(0, BS_BITMAP);
	m_CB13.SetBitmap(hBmp3);
	m_CB18.ModifyStyle(0, BS_BITMAP);
	m_CB18.SetBitmap(hBmp3);
	m_CB23.ModifyStyle(0, BS_BITMAP);
	m_CB23.SetBitmap(hBmp3);
	m_CB28.ModifyStyle(0, BS_BITMAP);
	m_CB28.SetBitmap(hBmp3);

	m_CB4.ModifyStyle(0, BS_BITMAP);
	m_CB4.SetBitmap(hBmp4);
	m_CB9.ModifyStyle(0, BS_BITMAP);
	m_CB9.SetBitmap(hBmp4);
	m_CB14.ModifyStyle(0, BS_BITMAP);
	m_CB14.SetBitmap(hBmp4);
	m_CB19.ModifyStyle(0, BS_BITMAP);
	m_CB19.SetBitmap(hBmp4);
	m_CB24.ModifyStyle(0, BS_BITMAP);
	m_CB24.SetBitmap(hBmp4);
	m_CB29.ModifyStyle(0, BS_BITMAP);
	m_CB29.SetBitmap(hBmp4);

	m_CB5.ModifyStyle(0, BS_BITMAP);
	m_CB5.SetBitmap(hBmp5);
	m_CB10.ModifyStyle(0, BS_BITMAP);
	m_CB10.SetBitmap(hBmp5);
	m_CB15.ModifyStyle(0, BS_BITMAP);
	m_CB15.SetBitmap(hBmp5);
	m_CB20.ModifyStyle(0, BS_BITMAP);
	m_CB20.SetBitmap(hBmp5);
	m_CB25.ModifyStyle(0, BS_BITMAP);
	m_CB25.SetBitmap(hBmp5);
	m_CB30.ModifyStyle(0, BS_BITMAP);
	m_CB30.SetBitmap(hBmp5);
}
///////////////////////////////////////////////////////////////////////////////
int CJeopardyDlg::AdjustScore(int nButton)
{
	int nScore = 0;
	if (m_nRoundNumber == 1)
	{
		nScore = 100 * nButton;
	}
	else
	{
		nScore = 200 * nButton;
	}

	return nScore;
}