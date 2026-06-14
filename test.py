from ctypes import *

lib = CDLL("./library.so")

lib.init_library.restype = None

lib.get_book_count.restype = c_int
lib.get_member_count.restype = c_int
lib.get_record_count.restype = c_int

lib.shutdown_library.restype = None

lib.init_library()

print("Books:", lib.get_book_count())
print("Members:", lib.get_member_count())
print("Records:", lib.get_record_count())

lib.shutdown_library()