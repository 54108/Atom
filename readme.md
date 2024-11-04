# This is a peer-to-peer chat software

- use the follow instruction to install required packages

```
sudo apt install libwayland-dev wayland-protocols pkg-config libx11-dev xorg-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxkbcommon-dev vulkan-tools libvulkan-dev vulkan-utility-libraries-dev
```

- use the follow instruction to build it

```
git clone --recurse-submodules https://github.com/54108/Atom.git
mkdir build && cd build
cmake ..
make
```
- use the follow instruction to run it
```
./atom
```

### now it is linux only and just have main window.