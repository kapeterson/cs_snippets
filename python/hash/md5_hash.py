import hashlib
import argparse


str = "mypassword"
md = hashlib.md5(str).hexdigest()
print md


