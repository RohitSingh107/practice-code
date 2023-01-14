#!/usr/bin/fish
set theme (zenity --list \
    --title="Choose Theme" \
    --column="Theme" \
    blocks \
    colorblocks \
    cuts \
    docky \
    forest \
    grayblocks \
    hack \
    material \
    shades \
    shapes)
#echo $theme
#echo ~/.config/polybar/launch.sh --"$theme"
bash ~/.config/polybar/launch.sh --"$theme"
