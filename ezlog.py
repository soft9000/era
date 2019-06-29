#!/usr/bin/env python3

from datetime import datetime as zdatetime
from email import utils


""" Create + append a console-line message to 'logger.log' in the pwd. """

class EzLog():

    def _hack(self, message):
        znow = zdatetime.now()
        znow = utils.localtime(znow)
        self.local_date = znow.strftime(format=self.LFORMAT)
        self.message = str(message)

    @classmethod
    def Create(recipe):
        import sys
        words = sys.argv[1:]
        message = ''
        for word in words:
            if len(message) is not 0:
                message += ' '
            message += word
        return recipe(message)

    def __init__(self, message):
        """ Taking care of beez-nice """
        self.LFORMAT = '%Y/%m/%d: %H.%M.%S (LOCAL)'
        self.UFORMAT = '%Y/%m/%d: %H.%M.%S [%z]'
        self._hack(message)

    def __repr__(self):
        return self.local_date + "\t" + self.message + "\n"

    def __str__(self):
        return repr(self)

    def hack(self, message):
        """ Update the time, as well as the message """
        self._hack(message)

    def isNull(self):
        return len(self.message) == 0


if __name__ == '__main__':
    entry = EzLog.Create()
    with open("./logger.log", "a") as fp:
        if entry.isNull():
            entry.message = "This is a test"
        fp.write(str(entry))
