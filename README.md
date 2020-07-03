# Personal bin programs

These are just some scripts and programs that I use on a daily basis.

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

backlight <u>integer between -1000 to 1000</u>

## book - BASH

Checks if a pdf exists in the Book directory and opens it using the 'open'
script.

### usage

book <u>File</u>

## devour - BASH

Written by salman-abedin and cloned from
https://github.com/salman-abedin/devour/.

## open - BASH

Opens a file based on its file extension.

### usage

open [options] <u>File</u>...

## tmplt - C

Checks if templates exist in the Template directory and concatenates them.

tmplt <u>tmplt_dir</u> <u>tmplt_name</u> <u>output_file</u>
tmplt -d <u>tmplt_dir</u>... -f <u>tmplt_name</u>... -o <u>output_file</u>... <u>repeat_flags_and_args</u>


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

vlang <u>filetype extension|'all'</u>
