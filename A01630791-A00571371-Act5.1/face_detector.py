import random

import cv2
import dlib
import imutils
import numpy as np

# Draw a point
def draw_point(img, p, color):
    cv2.circle(img, p, 2, color, cv2.FILLED, cv2.LINE_AA, 0)

# Read image from image path
# img = cv2.imread('oscar.jpeg', 1)
# img = cv2.imread('rodrigo.jpeg', 1)
img = cv2.imread('obama.jpeg', 1)

# set up the 68 point facial landmark detector
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")

# convert to grayscale
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# detect faces in the image
faces_in_image = detector(img_gray, 0)

# Process only first image
face = faces_in_image[0]

# assign the facial landmarks
landmarks = predictor(img_gray, face)

# unpack the 68 landmark coordinates from the dlib object into a list
points = []
for i in range(0, landmarks.num_parts):
    points.append((landmarks.part(i).x, landmarks.part(i).y))

points2 = np.rot90(points, 4)

file = open("data.txt", "w")
file.write(str(landmarks.num_parts) + "\n")

for p in points:
    # draw_point(img_gray, p, (0, 0, 255))
    file.write(str(p[0]) + " " + str(p[1]) + "\n")

