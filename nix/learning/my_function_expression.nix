

# a: a + 1 # Valid expression

# { a, b } : a + b

# { a ? 14, b } : a + b

# { a , b } :
# {
#   c = a + b;
#   d = "returnig atribute set";
# }

{ a ? 100, b, ... }@args : if args.c then a else b
