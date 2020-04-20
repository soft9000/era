#!/usr/bin/env python3
""" 
Mission: Create + append a console-line message to 'logger.log' in the pwd.
Project: Python 4000, Linux & DevOps (Udemy)
URL:     https://www.udemy.com/course/python-4000-gnu-devops
File:    ezlog.py
Version: 3.0 (list/read update & test case)
"""
import os
import os.path
from datetime import datetime as zdatetime
from email import utils

class EzLog():

    LOGFILE = "./logger.log"

    def __init__(self, message = ''):
        self.LFORMAT = '%Y/%m/%d: %H.%M.%S (LOCAL)'
        self.UFORMAT = '%Y/%m/%d: %H.%M.%S [%z]'
        self._hack(message)

    def _hack(self, message):
        znow = zdatetime.now()
        znow = utils.localtime(znow)
        self.local_date = znow.strftime(format=self.LFORMAT)
        self.message = str(message)

    def __str__(self):
        return self.local_date + "\t" + self.message + "\n"

    def hack(self, message):
        """ Update the time, as well as the message """
        self._hack(message)

    def is_null(self):
        return len(self.message) == 0

    @staticmethod
    def Create(message):
        entry = EzLog(message)
        with open(EzLog.LOGFILE, "a") as fp:
            if entry.is_null():
                entry.message = "This is a test"
            fp.write(str(entry))
        print("Logged.")

    @staticmethod
    def List(message):
        try:
            nelem = int(message)
            if nelem < 1:
                print(f"Ignoring {nelem}...")
                return
            with open(EzLog.LOGFILE) as fh:
                for which in range(nelem):
                    line = fh.readline()
                    if not line:
                        print("(eof)")
                        return
                    else:
                        print(f"{which+1}.) {line.strip()}")
        except Exception as ex:
            raise ex


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--create",
                        type=EzLog.Create,
                        help="Log message")
    parser.add_argument("-l", "--list",
                        nargs=1,
                        type=EzLog.List,
                        help="List recent messages")
    if os.path.exists(EzLog.LOGFILE):
        os.unlink(EzLog.LOGFILE)
    parser.parse_args(["-c", "This One."])
    parser.parse_args(["-c", "This Two."])
    parser.parse_args(["-c", "This Three."])
    parser.parse_args(["-c", "This Four."])
    parser.parse_args(["-l", "1"])
    parser.parse_args(["-l", "11"])
    parser.parse_args(["-l", "0"])
    parser.parse_args(["-l", "-1"])
