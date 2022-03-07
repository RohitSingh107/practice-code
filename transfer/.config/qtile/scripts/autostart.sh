#!/bin/bash

function run {
  if ! pgrep $1 ;
  then
    $@&
  fi
}



if [ $DESKTOP_SESSION = 'qtile-wayland' ]
then
    swaybg -i mydata/Pictures/wallpapers/0051.jpg &
else
    lxsession &
    picom --config .config/picom/picom-blur.conf --experimental-backends &
    numlockx on &
    feh --randomize --bg-fill /home/rohit/Pictures/wallpapers/*.jpg


    #nitrogen --random --set-zoom-fill &
    #feh --bg-fill ~/.config/qtile/flower.jpg &
    fi

# run cbatticon &
# run dunst &
# run nm-applet &
# run pamac-tray &
# run blueman-applet &
# run volumeicon &


#run discord &
#nitrogen --random --set-zoom-fill &
#run caffeine -a &
#run vivaldi-stable &
#run firefox &
#run thunar &
#run dropbox &
#run insync start &
#run spotify &
#run atom &
#run telegram-desktop &
