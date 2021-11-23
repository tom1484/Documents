function mandel(z)
    c = z
    max = 80
    for n = 1:max
        if abs(z) > 2
            return n-1
        end
        z = z^2 + c
    end
    return max
end
