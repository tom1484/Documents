using Images, FileIO


img_path = "spectrum.png"
spec = load(img_path)[1, :]

C = 350

minWl, maxWl = 380e-9, 780e-9
colors = [ (x, spec[round(Int, c)]) for (x, c) in zip(LinRange(minWl, maxWl, C), 
                                                      LinRange(1, size(spec)[1], C)) ]
# print(colors)

N = 1601
K = 5
R, D = 10, 0.06 * pi
d = 50000e-9
A = 4 * d
dx = d / N

x = collect(LinRange(D / 2, -D / 2, N))
slit = collect(LinRange(d / 2, -d / 2, N))

slits = [ slit .+ (i - (K + 1) / 2) * A for i in K:-1:1 ]
# print(slits[1])

E = zeros(RGB, N)
E_spec = zeros(N, C)

for (c, (lamda, clr)) in zip(1:C, colors)
    E_phase = zeros(ComplexF64, N)
    k = 2 * pi / lamda

    for X in slits
        r = sqrt.((x .- X) .^ 2 .+ R ^ 2)
        phi = (r .- R) .* k
        dPhase = cos.(phi) + sin.(phi) .* 1im
        E_phase .+= dPhase
    end
    E_spec[:, c] = abs.(E_phase)

    E .+= E_spec[:, c] .* clr
end

E ./= max(maximum(red.(E)), maximum(green.(E)), maximum(blue.(E)))
E_spec ./= maximum(E_spec)

E_img = vcat([E' for i in 1:N]...)
save("result.png", E_img)


