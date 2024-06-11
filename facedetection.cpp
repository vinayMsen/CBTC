/*
opencv2/opencv.hpp`: The core OpenCV functions.
    - opencv2/objdetect.hpp`: Functions for object detection (in this case, face detection).

Load the Haar Cascade Classifier**:
    - Haar cascades are pre-trained classifiers for detecting objects (in this case, faces). OpenCV provides XML files for these cascades.

*/


#include <bits/stdc++.h>

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main() {
    // Load the Haar Cascade for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error loading haarcascade_frontalface_default.xml" << endl;
        return -1;
    }

    // Capture video from the webcam
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error opening video capture" << endl;
        return -1;
    }

    Mat frame, gray;
    vector<Rect> faces;

    while (true) {
        // Capture each frame
        cap >> frame;
        if (frame.empty()) {
            cerr << "No captured frame -- Break!" << endl;
            break;
        }

        // Convert frame to grayscale
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Detect faces
        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2);
        }

        // Display the frame
        imshow("Face Detection", frame);

        // Break the loop if 'q' is pressed
        if (waitKey(10) == 'q') {
            break;
        }
    }

    return 0;
}




