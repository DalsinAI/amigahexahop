#! /bin/sh

# Compiler settings.
VERSION=1.1.0
PATH="$PATH:/opt/fgdkit/bin"
LIN32HOST=i686-fgdkit-linux
LIN32PREFIX=/opt/fgdkit/i686-fgdkit-linux
LIN32LIBS="libfreetype.so.6 libogg.so.0 libvorbis.so.0 libvorbisfile.so.3 libz.so.1 libSDL_mixer-1.2.so.0 libSDL_ttf-2.0.so.0"
WIN32HOST=i686-fgdkit-mingw32
WIN32PREFIX=/opt/fgdkit/i686-fgdkit-mingw32
WIN32LIBS="libfreetype-6.dll libogg-0.dll libvorbis-0.dll libvorbisfile-3.dll SDL.dll SDL_mixer.dll SDL_ttf.dll zlib1.dll"

echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@@@@@ BUILDING SOURCE TARBALL @@@@@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

./configure
rm -Rf hex-a-hop-$VERSION
make distcheck
# hex-a-hop-$VERSION.tar.gz

echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@@ BUILDING LINUX 32-BIT BINARY @@@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

rm -Rf hex-a-hop-$VERSION
./configure --host=$LIN32HOST --prefix="$PWD/hex-a-hop-$VERSION" --with-sdl-prefix="$LIN32PREFIX" --enable-relpath
make clean all install
mkdir -p hex-a-hop-$VERSION/lib
for lib in $LIN32LIBS; do cp $LIN32PREFIX/lib/$lib hex-a-hop-$VERSION/lib; done
tar czf hex-a-hop-$VERSION-linux32.tar.gz hex-a-hop-$VERSION

echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@ BUILDING WINDOWS 32-BIT BINARY @@@@@@@@@@@@@@@"
echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"

rm -Rf hex-a-hop-$VERSION
./configure --host=$WIN32HOST --prefix="$PWD/hex-a-hop-$VERSION" --with-sdl-prefix="$WIN32PREFIX" --disable-sdltest --enable-relpath
make clean all install
for lib in $WIN32LIBS; do cp $WIN32PREFIX/bin/$lib hex-a-hop-$VERSION; done
rm -R hex-a-hop-$VERSION-win32.zip
zip -r hex-a-hop-$VERSION-win32.zip hex-a-hop-$VERSION
