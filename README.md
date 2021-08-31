<p align="center">
  <img src="https://user-images.githubusercontent.com/69415374/131396754-2fc06d8f-b3b0-4917-b9bb-e09fd9eeda0d.jpg" />
</p>
<br>
<p align="center">
  Documentation for Primal OS
</p>
<details>
  <summary> License/Right </summary>
  <br>
  Copyright (c) 2021 Novus Alex
  <br>
  <br>
  Permission is hereby granted, free of charge, to any person obtaining a copy<br>
  of this software and associated documentation files (the "Software"), to deal<br>
  in the Software without restriction, including without limitation the rights<br>
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>
  copies of the Software, and to permit persons to whom the Software is<br>
  furnished to do so, subject to the following conditions:<br>
  <br>
  The above copyright notice and this permission notice shall be included in all<br>
  copies or substantial portions of the Software.<br>
  <br>
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>
  SOFTWARE.<br>
</details>

## Support

| Platform         | Kernel Support    | Intel support     | AMD support       | 
| ---------------- | ----------------- | ----------------- | ----------------- |
| 32bits		       | No		             | No                | No                |
| 64bits			     | Yes			         | Yes               | Yes               |

 * For the moment, only 64bits platforms are supported but we are working on 32bits support!
<br>

| Drivers          | Status            |
| ---------------- | ----------------- |
| Keyboard         | Yes               |
| Mouse            | No                |
| Sound            | No                |
| GPU              | No                |
| Ports            | No                |

## How to build

First method (get iso file from github)
 * Download the latest release

<br>

Second method (build on your pc)
 * Install docker
 * Run the docker file to install the build environment (Special thanks to randomdude for buildenv)
 * ``docker build buildenv -t primal-buildenv``
 * Then start the machine
 * ``docker run --rm -it -v "%cd%":/root/env primal-buildenv``
 * Whan you are on the machine build primal with make
 * ``make build-x86_64``
 * You will see the os iso file ``/dist/x86_64/primal.iso``

## How to run

Run on a virtual machine (example with QEMU)
 * Fisrt install a virtual machine hoster such as QEMU or VirtualBox
 * Run the command in your cmd (only for QEMU)
 * ``qemu-system-x86_64 -cdrom dist/x86_64/primal.iso``
 * For other softwares, follow tutorials to start a custom virtual machine

<br>

Run on a real computer
 * This option is not the best at this time but I will update the bootloader in the future
 * Run a ISO to USB Stick converter like BalenaEtcher and select the iso file
 * Plug your USB Stick into your computer you want to run the os on
 * In the boot option, select boot with usb and the os will boot!

## Terminal Commands
 * Only simple commands to test the terminal
 <br>
 
 ``whoiam`` - ``output: username``
 <br>
 ``clear`` - ``clear the screen``
