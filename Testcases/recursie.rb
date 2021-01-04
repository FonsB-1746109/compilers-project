def f (x)
  a = 2*x
  while (a < 6)
    a += f(a)
    return x*99
  end

  return a*3
end
print(f(1))


