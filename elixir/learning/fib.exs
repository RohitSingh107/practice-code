
defmodule Mymodule do
  def fib(n) do
    IO.puts "n is #{n}"
    if n <= 1 do
      n
    else
      fib(n-1) + fib(n-2)
    end
  end
end

IO.puts Mymodule.fib(10)
