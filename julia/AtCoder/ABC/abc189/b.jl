parseInt(x) = parse(Int, x)

function main()
    n, x = map(parseInt, split(readline()))
    #elements = [readline() for _ = 1 : n]
    arr = hcat((e -> parse.(Int, e)).(split.([readline() for _ = 1 : n]))...)
    alc_sum = 0
    for i in 1 : n
        alc_sum += arr[2i-1]*arr[2i]/100
        if alc_sum > x
            println(i)
            break
        end
        if i == n
            println(-1)
        end
    end
end

main()