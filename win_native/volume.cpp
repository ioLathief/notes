#include <windows.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>
#include <mmsystem.h>

//volume example
bool update_vol(double nVolume, bool bScalar) {

    HRESULT hr = NULL;
    bool decibels = false;
    bool scalar = false;
    double newVolume = nVolume;

    CoInitialize(NULL);
    IMMDeviceEnumerator *deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
                          __uuidof(IMMDeviceEnumerator), (LPVOID *) &deviceEnumerator);
    IMMDevice *defaultDevice = NULL;

    hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    deviceEnumerator = NULL;

    IAudioEndpointVolume *endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
                                 CLSCTX_INPROC_SERVER, NULL, (LPVOID *) &endpointVolume);
    defaultDevice->Release();
    defaultDevice = NULL;

    // -------------------------
    float currentVolume = 0;
    endpointVolume->GetMasterVolumeLevel(&currentVolume);
    //printf("Current volume in dB is: %f\n", currentVolume);

    hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
    //CString strCur=L"";
    //strCur.Format(L"%f",currentVolume);
    //AfxMessageBox(strCur);

    // printf("Current volume as a scalar is: %f\n", currentVolume);
    if (!bScalar) {
        hr = endpointVolume->SetMasterVolumeLevel((float) newVolume, NULL);
    } else {
        hr = endpointVolume->SetMasterVolumeLevelScalar((float) newVolume, NULL);
    }
    endpointVolume->Release();

    CoUninitialize();

    return FALSE;
}

double get_vol() {
    float currentVolume = 0;

    CoInitialize(NULL);
    IMMDeviceEnumerator *deviceEnumerator = NULL;
    CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator),
                     (LPVOID *) &deviceEnumerator);
    IMMDevice *defaultDevice = NULL;
    deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    deviceEnumerator = NULL;

    IAudioEndpointVolume *endpointVolume = NULL;
    defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *) &endpointVolume);
    defaultDevice->Release();
    defaultDevice = NULL;

    float fLevel;
    endpointVolume->GetMasterVolumeLevel(&fLevel);


    endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);
    endpointVolume->Release();

    CoUninitialize();

    return (double) (currentVolume * 100);
}

void simulate_keypress(BYTE vkCode) {
    // Simulate a key press
    keybd_event( vkCode,
                 0x45,
                 KEYEVENTF_EXTENDEDKEY | 0,
                 0 );

    // Simulate a key release
    keybd_event( vkCode,
                 0x45,
                 KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                 0);

}

int main() {
    update_vol(get_vol() / 100 + 0.01, true); //Increase volume by one
    simulate_keypress(VK_VOLUME_UP);

    return 0;
}