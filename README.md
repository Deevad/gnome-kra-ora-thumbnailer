gnome-kra-ora-thumbnailer
=========================

A **noob-made** thumbnailer ( app; 'File' aka Nautilus ) for KRA ( Krita native file ) and ORA ( open-raster ) for the Gnome desktop recent version ( &lt; 3.10 )   

___

##Dependencies

Get **unzip** and **image-magick** from your package manager

##Installation

###1)
Get the files
```
git clone https://github.com/Deevad/gnome-kra-ora-thumbnailer.git
cd gnome-kra-ora-thumbnailer
```
Or download it here :  [ gnome-kra-ora-thumbnailer master.zip on Github](https://github.com/Deevad/gnome-kra-ora-thumbnailer/archive/master.zip)
Then extract, and open a terminal in the folder. 

Copy **kra.thumbnailer** and **ora.thumbnailer** to /usr/share/thumbnailers

```
sudo cp kra.thumbnailer /usr/share/thumbnailers/kra.thumbnailer 
sudo cp ora.thumbnailer /usr/share/thumbnailers/openraster.thumbnailer 
```

3. Copy **ora-thumbnailer** and **kra-thumbnailer** to /usr/bin/ and give them permission to execute. 


4. Delete **~/.cache/thumbnails** folder 

5. Quit all 'Files/Nautilus' : **nautilus -q**

6. then restart 'File' via Activities.

Done.

##Terminal tips

Copy file with permission :
```
sudo cp source/path/to/your.file destination/path/to/your.file 
```

Turning a file to execute mode :
```
sudo chmod +x /path/to/your.file
```

Remove a folder :
```
rm -R ~/.cache/thumbnails
```
