## Basic Trojan

A Trojan, or Trojan horse, is a type of malicious software that disguises itself as a legitimate program to deceive users into installing it. Unlike viruses or worms, Trojans do not replicate themselves but instead create a backdoor for attackers to gain unauthorized access to a system. Once installed, a Trojan can perform various malicious activities, such as stealing sensitive data, spying on user activities, or allowing remote control of the infected device. Trojans are often spread through phishing emails, fake software downloads, or malicious attachments, making cybersecurity awareness essential to prevent infections.

In this basic Trojan project, I intended to create an executable that hides itself on the victim's machine and plays a song. It is important to note that most Trojans do not reveal their presence; instead, they typically remain hidden to steal private data from the user. This behavior can be observed in keylogger Trojans, rootkit Trojans, and similar types of malware.

---

## 📂 Estrutura do Projeto

```
📁 Basic_trojan
├── 📁 Trojan  # Stores the trojan files 
│   ├── main.cpp
│   ├── minimized_main.cpp
│   ├── prankware.dev
│   ├── google2.ico
│   ├── temp_music.mp3
├── make_bin.c  # Code used to convert music.mp3 in a byte array (music_array.txt)
├── music_array.txt
├── music.mp3 
├── infosec.pdf
```

---

## ✅ Project checklist

### 📌 Features done in the project:

- [OK] Make a file that runs in stealth mode, that is, without alarming the user.
- [OK] Change the `.ico` of the file, to make it less noticeable in the task manager.
- [OK] Find a way to play the music without the user having the `.mp3` file.

---

## 🔥 How to run the project

To run the trojan it's sufficient to run the prankware.exe in your machine. Have in sight
that the app will hide itself but it can be found in the task manager, to stop it you can 
just finish the task there.

To replicate the project it is sufficient to follow the steps in the Basic_trojan/infosec.pdf

---

## 🛠️ Applied Knowledge
- **Dev-C++**
- **C++**
- **windows.h**
- **file manipulation**
---

## 📌 Explaining the project

**Make a file that runs in stealth mode, that is, without alarming the user.**

To achieve this, I used the `FreeConsole()` function from the `windows.h` library. This function hides the console window, allowing the application to run in stealth mode. 

**Change the `.ico` of the file, to make it less noticeable in the task manager.**

Changing the file icon is necessary because if the executable appears suspicious, users are unlikely to open it. To address this, I found an `.ico` file online and applied it through the project settings in Dev-C++.

**Find a way to play the music without the user having the .mp3 file.**

To accomplish this, I converted the music file into a byte array and embedded it directly into the code. The script responsible for this process is located at `/Prankware/Basic_trojan/make_bin.c`, which generates `music_array.txt` containing the byte elements of the music file.

Once the byte array is obtained, it is integrated into the main code. In `minimized_main.cpp`, the program creates a temporary `.mp3` file and writes the byte array into it, enabling playback.

## 📌 Final considerations

This project was developed based on `infosec.pdf`, a chapter from the textbook used in the Information Security course at UFPE.
