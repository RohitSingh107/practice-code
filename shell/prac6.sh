#!/bin/bash
_admin_ip="202.54.1.33|MUM_VPN_GATEWAY 23.1.2.3|DEL_VPN_GATEWAY 13.1.2.3|SG_VPN_GATEWAY"
for e in $_admin_ip
do
   echo allow from "${e%%|*}" to any port 22 proto tcp comment "Open SSH port for ${e##*|}"
done


PKGS="php7-openssl-7.3.19-r0  php7-common-7.3.19-r0  php7-fpm-7.3.19-r0  php7-opcache-7.3.19-r0 php7-7.3.19-r0"
for p in $PKGS
do
   echo "Installing $p package"
done


# for i in $(ls)
for i in *
do
  echo "Item is $i"
done
