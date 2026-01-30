Mini Zocdoc – Hackathon Project

Overview

Mini Zocdoc is a simple healthcare appointment booking system designed for hackathons. It features a dual-sided system:
Patient side – book and cancel appointments.
Doctor side – view earnings and cancelled slots.
It demonstrates real-time booking, cancellation, and earnings in ₹, with a colorful and interactive UI.

Features

Patient Side
Enter your name and select a doctor.
Book appointments and view all your booked appointments.
Cancel appointments, which updates doctor earnings.
Doctor Side
View earnings in ₹.
See available slots (blue), booked slots (dark pink), and cancelled slots (red).

Backend (C)

Console-based program.
Tracks bookings, cancellations, and doctor earnings in ₹.
Menu options:
View doctors and slots
Book appointment
Cancel appointment
Exit

Frontend (HTML/JS/CSS)

Interactive web interface.
Gradient background with blue & dark pink theme.
Card-style layout with hover effects.

How It Works

Booking a slot: Patient books → slot disappears → doctor earns ₹100.
Cancelling a slot: Patient cancels → slot returns → doctor loses ₹100 → cancelled slot shown in red for doctor.
Backend and frontend run independently:
Backend handles logic in C.
Frontend handles interactive visuals in browser.
Responsive for patient and doctor views.

Color-coded slot status for clarity.
