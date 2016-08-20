#!/usr/bin/env bash
if ( test "`uname -s`" = "Darwin" )
then
  brew update
  brew install cmake
  echo
else
  sudo add-apt-repository --yes ppa:kalakris/cmake
  sudo apt-get update -qq
  sudo apt-get install cmake doxygen
fi
