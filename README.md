# Personal bin programs

These are just some scripts and programs I've written that I use on a daily basis.

To use the programs written and C, you'll want to configure the header files
in 'CBuildFiles/config/' to and then run 'make' in the 'CBuildFiles' directory.
The symbolic links to the generated binaries are already in the base directory.

## backlight - C

Increments or decrements a file containing one number by a tenth of a percentage of some
statically defined maximum number. Both the file name and the maximum number
are defined in the backlight.h configuration file. This program can really be used to
change a lot of files, but I wrote it to just change the backlight on my
monitors. May need to be run as sudo.

### usage

backlight integer between -1000 to 1000

## book - BASH

Checks if a pdf exists in the Book directory and opens it using the 'open'
script. Uses dmenu to traverse directories and select files.

### usage

book

## icpp - BASH

Pseudo-interpreter for c++. Compiles a temporary binary, runs it, and then deletes it. If no argument is specified, it will search for main.cpp. I use this for competitive programming.

### usage

icpp [File]

## open - BASH

Opens a file based on its file extension.

### usage

open [options] File...

## pullall - BASH

Reads a file specified in script and pulls from origin master from all of them
asynchronously.

### usage

pullall

## screenshot - BASH

Takes a selected area screenshot with scrot and has the user enter a name with
dmenu.

### usage

screenshot

## swap - BASH

Swaps two filenames.

### usage

swap File1 File2

## tmplt - C

Checks if templates exist in the Template directory and concatenates them.

### usage

tmplt tmplt\_dir tmplt\_name output\_file

tmplt -d tmplt\_dir... -f tmplt\_name... -o output\_file... repeat\_flags\_and\_args

## toggle - BASH

Runs program on if it's not running and kills it if it is. I use this for
turning off and on my compositor.

### usage

toggle Program1 Program2

## ucivpn - BASH

Opens a vpn tunnel and connects to the UCI VPN after authenticating login
infromation. Needs to be run as sudo and requires the packages openvpn,
openconnect, vpnc, net-tools on Arch-based distros.

### usage

sudo ucivpn [close]

## vlang - BASH

Open individual settings for vim languages in the .vim/lang folder. Useful
to keep the vimrc small and organized. 'all' will open all filetypes in vim.

### usage

vlang filetype\_extension|'all'
