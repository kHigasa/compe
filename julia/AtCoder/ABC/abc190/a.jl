parseInt(x) = parse(Int, x)
a,b,c = map(parseInt, split(readline()))
if a > b
    println("Takahashi")
elseif a < b
    println("Aoki")
else
    if c == 0
        println("Aoki")
    else
        println("Takahashi")
    end
end