gnome-kra-ora-thumbnailer
=========================

A **noob-made** thumbnailer ( app; 'File' aka Nautilus ) for KRA ( Krita native file ) and ORA ( open-raster ) for the Gnome desktop recent version ( &lt; 3.10 )   

___

##Dependencies

Get **unzip** and **image-magick** from your package manager

##Installation
1. Get the 4 files

2. Copy **kra.thumbnailer** and **ora.thumbnailer** to /usr/share/thumbnailers

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
