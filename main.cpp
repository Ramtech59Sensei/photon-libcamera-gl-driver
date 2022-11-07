#include "libcamera_jni.hpp"
#include "camera_runner.h"

#include <chrono>
#include <thread>


int main() {
    Java_org_photonvision_raspi_LibCameraJNI_createCamera(nullptr, nullptr, 1920, 1080, 30);
    Java_org_photonvision_raspi_LibCameraJNI_destroyCamera(nullptr, nullptr);
    Java_org_photonvision_raspi_LibCameraJNI_createCamera(nullptr, nullptr, 1920, 1080, 30);
    Java_org_photonvision_raspi_LibCameraJNI_destroyCamera(nullptr, nullptr);
    Java_org_photonvision_raspi_LibCameraJNI_createCamera(nullptr, nullptr, 1920, 1080, 30);
    Java_org_photonvision_raspi_LibCameraJNI_destroyCamera(nullptr, nullptr);
    Java_org_photonvision_raspi_LibCameraJNI_startCamera(nullptr, nullptr);

    using namespace std::chrono_literals;

    std::this_thread::sleep_for(3s);

    Java_org_photonvision_raspi_LibCameraJNI_stopCamera(nullptr, nullptr);
    Java_org_photonvision_raspi_LibCameraJNI_destroyCamera(nullptr, nullptr);
    Java_org_photonvision_raspi_LibCameraJNI_createCamera(nullptr, nullptr, 640, 480, 90);
    Java_org_photonvision_raspi_LibCameraJNI_startCamera(nullptr, nullptr);

    std::this_thread::sleep_for(3s);

    return 0;
}
