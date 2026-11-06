Hex-a-hop for AmigaOS 3.x
=========================

Hex-a-hop (Tom Beaumont and others, http://hexahop.sourceforge.net), the
puzzle game on hexagonal tiles: break every green tile and step onto a safe
one without getting stuck, with infinite undo. For AmigaOS 3.x on a 68040
or 68060 with an FPU and an RTG screen, on OpenGPU's SDL 1.2
(sdl12-compat).

Base: upstream's tree of 26 September 2014 (version 1.1.0+git20140926), as
Debian packages it: hex-a-hop_1.1.0+git20140926.orig.tar.xz (sha256
7c53916830db8f15fff87b4873acb83693d63b66e74cb36bcd39507bce1d56c0). This
tree has free music and sounds in place of the 1.1.0 release's non-free
ones (CC BY-NC-SA and CC Sampling Plus). Branch team2/hexahop-amiga.

Status: builds; not yet run in the lab.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the HexAHop icon, or run HexAHop from a Shell. The game reads its
levels, pictures, sounds and font from the drawer's data/, and keeps its
saved games there too.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static FreeType, libpng, zlib and bzip2 (see the Makefile's
head), and the host's GStreamer (gst-launch-1.0) for the sounds. The drawer
is dist/HexAHop (and dist/HexAHop.info).


What was changed
----------------

- src/gfx.cpp: main() first moves into the drawer (amiga/amiga_start.c),
  and closes at exit the screens SDL2.module 0.6 can leave
  (amiga/amiga_screens.c); the icon's path has no "//" (AmigaDOS's
  parent). amiga/stack.c: 512 KB of stack.
- src/system-directory.c, private_concat_paths(): upstream looked at the
  terminating nul for a '/', so it always added one, and every sound's path
  had a "//" in it (on AmigaDOS, the parent drawer). It looks at the last
  character now (a ':' too).
- src/text.cpp: no "//" between the drawer and the font's name.
- src/hex_puzzzle.cpp: the saved games in the drawer's data/, as on
  Windows (upstream on Unix: ~/.hex-a-hop).
- The paths: DATADIR is PROGDIR:data/, the font DejaVu Sans Bold (as
  upstream's configure recommends; this tree has no font of its own).
- No SDL_image, SDL_mixer or SDL_ttf 1.2 for OpenGPU's SDL 1.2: the Team's
  amiga/sdl_image_lite.c (PNG on libpng), amiga/sdl_mixer_lite.c (WAV) and
  SDL_ttf 2.0.11 (amiga/sdl_ttf, zlib licence) stand in, as in the
  Holotz's Castle and BlockOut II ports. SDL_RWFromFile is stdio
  (amiga/amiga_rwops.c).
- The sounds and music are WAV in the drawer (amiga/tools/ogg2wav.py: the
  68k does not decode Vorbis): 16-bit PCM effects, IMA ADPCM music.


Licences
--------

Hex-a-hop: GPL 2 or later (COPYING.txt). Its music and sounds: CC BY-SA
3.0, CC BY 3.0 and public domain, each file's in data/LICENCES.txt. DejaVu
Sans: data/DejaVu-LICENSE.txt. SDL_ttf 2.0.11: zlib (SDL_ttf-COPYING.txt).
The Amiga files (amiga/): the AmiCradle Team; the SDL_image, SDL_mixer and
rwops shims come from the Team's Wizznic and Gigalomania ports and are
GPL 3 or later, so the program as built here is GPL 3 or later.
