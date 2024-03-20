
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {


  buildInputs = with pkgs; [
    postgresql
  ];

  shellHook = ''
  export PGHOST=$PWD/postgres
  export PGDATA=$PGHOST/data
  export PGDATABASE=postgres
  export PGLOG=$PGHOST/postgres.log

  mkdir -p $PGHOST

  if [ ! -d $PGDATA ]; then
    initdb --auth=trust --no-locale --encoding=UTF8
  fi

  if ! pg_ctl status
  then
    pg_ctl start -l $PGLOG -o "--unix_socket_directories='$PGHOST' --listen_addresses=localhost"
  fi
'';
}


