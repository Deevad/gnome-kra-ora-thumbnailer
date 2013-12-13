gnome-kra-ora-thumbnailer
=========================

![alt header](http://www.davidrevoy.com/data/images/blog/2013/11/kra-ora_thumbnailer_banner.jpg)


A thumbnailer for Gnome 'File' (aka Nautilus) and Cinnamon 'Nemo' for KRA ( Krita native file ) and ORA ( open-raster ).  

___

##Installation

Get the "build essential" from your package manager, autogen, cmake, git ...etc...

```
git clone https://github.com/Deevad/gnome-kra-ora-thumbnailer.git
cd gnome-kra-ora-thumbnailer
./autogen.sh
make
sudo make install
```
You can also download the source as a zip here : [ gnome-kra-ora-thumbnailer master.zip on Github](https://github.com/Deevad/gnome-kra-ora-thumbnailer/archive/master.zip)


##Post-install

Close all Nemo/Files/Nautilus running then clean your old thumbnail cache, 

```
rm -R ~/.cache/thumbnails
```
Re-open, check your *.kra files , and your *.ora files : should have thumbnail now.

*Notes :*
- Don't forget in 'preferences' to allow thumbnail preview for files larger than 100MB ; those layered files tend to be large. 
