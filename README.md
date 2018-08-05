gnome-kra-ora-thumbnailer
=========================

![alt header](http://www.davidrevoy.com/data/images/blog/2013/11/kra-ora_thumbnailer_banner.jpg)


A thumbnailer for Gnome 'File' (aka Nautilus) and Cinnamon 'Nemo' for KRA ( Krita native file ) and ORA ( open-raster ).  

## Project is Archived:

**2018-04:** Repository archived on Github: the project moved to GNOME - YAY!  
**2018-08:** GNOME archived due to inactivity or deprecation - :-/    

Bleee.... After the full rewrite in C, I wasn't able to maintain it myself. Then I was happy when this project was joining the shiny new Git.Gnome in 2018. But sad to see the project was archived after 4month on the new platform. It feels litteraly like an _"Embrace, extend, and extinguish"_ strategy happened to this repository... So, I'm unarchiving to add this note to the README, then I'm re-Archiving it. At least, I guess it wasn't done "on purpose" by the GNOME project, but still... Not a good relationship.

**Where to go now?** To try maintaining the project, the repo you can contribute is in the Archive of GNOME now: **https://gitlab.gnome.org/Archive/gnome-kra-ora-thumbnailer** but if you want to apply something that works today for your GNOME install, **I advice the usage of: https://moritzmolch.com/1749 as an alternative**.

___

## Installation

Get the "build essential" from your package manager, autogen, cmake, git ...etc...

Get the sources :

```
git clone https://github.com/Deevad/gnome-kra-ora-thumbnailer.git
cd gnome-kra-ora-thumbnailer
```
Note : You can also download the source as a zip here : [ gnome-kra-ora-thumbnailer master.zip on Github](https://github.com/Deevad/gnome-kra-ora-thumbnailer/archive/master.zip)


Configure, build and install :
```
./autogen.sh
make
sudo make install
```



## Post-install

Close all Nemo/Files/Nautilus. 

Clean your old thumbnail cache : 

```
rm -R ~/.cache/thumbnails
```
Re-open, check your *.kra files , and your *.ora files : should have thumbnail now.

*Notes :*
- Don't forget in 'preferences' to allow thumbnail preview for files larger than 100MB ; those layered files tend to be large. 
