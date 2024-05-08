#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// SmartLight class
class SmartLight {
private:
    int brightness;
    bool status;

public:
    SmartLight() {
        brightness = 0;
        status = false;
    }

    void turnOnOff() {
        status = !status;
        cout << "Light turned " << (status ? "on" : "off") << endl;
    }

    void adjustBrightness(int newBrightness) {
        if (newBrightness >= 0 && newBrightness <= 100) {
            brightness = newBrightness;
            cout << "Brightness adjusted to " << brightness << endl;
        } else {
            cout << "Invalid brightness value" << endl;
        }
    }

    void displayStatus() {
        cout << "Light is currently " << (status ? "on" : "off") << " with brightness " << brightness << endl;
    }
};

// Thermostat class
class Thermostat {
private:
    float temperature;
    string mode;

public:
    Thermostat() {
        temperature = 0.0f;
        mode = "Off";
    }

    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        cout << "Temperature set to " << temperature << endl;
    }

    void changeMode(string newMode) {
        mode = newMode;
        cout << "Mode changed to " << mode << endl;
    }

    void displaySettings() {
        cout << "Thermostat is currently in " << mode << " mode with temperature " << temperature << endl;
    }
};

// SecurityCamera class
class SecurityCamera {
private:
    bool isRecording;
    string lastMotionTime;

public:
    SecurityCamera() {
        isRecording = false;
        lastMotionTime = "N/A";
    }

    void startRecording() {
        isRecording = true;
        time_t now = time(0);
        lastMotionTime = ctime(&now);
        cout << "Recording started" << endl;
    }

    void stopRecording() {
        isRecording = false;
        cout << "Recording stopped" << endl;
    }

    void updateLastMotionTime() {
        time_t now = time(0);
        lastMotionTime = ctime(&now);
    }

    void displayLastMotionTime() {
        cout << "Last motion detected at: " << lastMotionTime;
    }
};

int main() {
    // Create instances of devices
    SmartLight light;
    Thermostat thermostat;
    SecurityCamera camera;

    // Test SmartLight
    light.turnOnOff();
    light.adjustBrightness(75);
    light.displayStatus();

    // Test Thermostat
    thermostat.setTemperature(25.5);
    thermostat.changeMode("Heat");
    thermostat.displaySettings();

    // Test SecurityCamera
    camera.startRecording();
    camera.updateLastMotionTime();
    camera.displayLastMotionTime();

    return 0;
}
