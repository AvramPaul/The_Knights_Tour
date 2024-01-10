
FROM gcc:latest
WORKDIR /usr/src/knight.cpp
COPY knight.cpp .
RUN gcc -o myapp knight.cpp -lstdc++
CMD ["./myapp"]
