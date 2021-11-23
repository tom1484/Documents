mkdir tmp
cd ./tmp

sudo apt install -y libosmesa6-dev
sudo apt install -y python3.7-dev
sudo apt install -y libglew-dev

wget http://nixos.org/releases/patchelf/patchelf-0.10/patchelf-0.10.tar.bz2
tar xf patchelf-0.10.tar.bz2
cd patchelf-0.10
./configure --prefix="$HOME/.local"
make install
strip --strip-unneeded ~/.local/bin/patchelf
gzip -9 ~/.local/share/man/man1/patchelf.1
cd ../
rm patchelf-0.10.tar.bz2
rm -r patchelf-0.10

mkdir ~/.mujoco
wget https://www.roboti.us/download/mujoco200_linux.zip
unzip mujoco200_linux.zip
mv mujoco200_linux ~/.mujoco/mujoco200
rm mujoco200_linux.zip