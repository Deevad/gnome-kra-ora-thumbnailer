gnome-kra-ora-thumbnailer
=========================

![alt header](http://www.davidrevoy.com/data/images/blog/2013/11/kra-ora_thumbnailer_banner.jpg)


A **noob-made** thumbnailer ( app; 'File' aka Nautilus ) for KRA ( Krita native file ) and ORA ( open-raster ) for the Gnome desktop recent version ( &lt; 3.10 )   

___

##Dependencies

Get **unzip** and **image-magick** from your package manager

##Installation

###1) Get the files

####First method : 

Clone the Git ; you'll need obviously the package **git-core** installed to use **git**. 
```
git clone https://github.com/Deevad/gnome-kra-ora-thumbnailer.git
cd gnome-kra-ora-thumbnailer
```

####Second method :

Download it here :  [ gnome-kra-ora-thumbnailer master.zip on Github](https://github.com/Deevad/gnome-kra-ora-thumbnailer/archive/master.zip)
Then extract, and open a terminal in the folder. 

###2) Move the file to the right place

You'll need to copy **kra.thumbnailer** and **openraster.thumbnailer** to /usr/share/thumbnailers

```
sudo cp kra.thumbnailer /usr/share/thumbnailers/kra.thumbnailer 
sudo cp ora.thumbnailer /usr/share/thumbnailers/openraster.thumbnailer 
```

and then Copy **ora-thumbnailer** and **kra-thumbnailer** to /usr/bin/ and give them permission to execute. 

```
sudo cp ora-thumbnailer /usr/bin/ora-thumbnailer
sudo cp kra-thumbnailer /usr/bin/kra-thumbnailer
```

###3) Permissions

Some of those text files are scripts, and need a permission to run. 
```
sudo chmod +x /usr/bin/ora-thumbnailer
sudo chmod +x /usr/bin/kra-thumbnailer

```

###4) Clean cache

We need to delete previously made thumbnails; some files might have created a 'fail' thumbnail. Delete **~/.cache/thumbnails** folder 

```
rm -R ~/.cache/thumbnails
```


###5) Restart 'Files'

Files ( aka Nautilus ) can be quited this way 
```
nautilus -q**
```
Then restart 'File' via Activities.

Check your *.kra files , and your *.ora files, should be done.
