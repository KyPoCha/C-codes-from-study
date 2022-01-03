#!/bin/bash

if [[ $(cat code.output | grep -i warning) ]]
then
  cat code.ouput;
  exit 1;
fi
