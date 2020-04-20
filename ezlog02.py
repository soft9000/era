#!/usr/bin/env python3
""" 
Mission: Create + append a console-line message to 'logger.log' in the pwd.
Project: Python 4000, Linux & DevOps (Udemy)
URL:     https://www.udemy.com/course/python-4000-gnu-devops
File:    ezlog.py
Version: 2.0 (command-line injection test case)
"""
import os
import os.path
from datetime import datetime as zdatetime
from email import utils

class EzLog():

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
        with open("./logger.log", "a") as fp:
            if entry.is_null():
                entry.message = "This is a test"
            fp.write(str(entry))
        print("Logged.")


if __name__ == '__main__':
    import sys
    sys.argv.append("-c")
    sys.argv.append("This is a test message!")
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--create",
                        type=EzLog.Create,
                        help="Log message")
    args = parser.parse_args()
