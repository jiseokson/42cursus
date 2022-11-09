#!/bin/bash
ifconfig | grep "^\sether" | awk '{print $2}'
