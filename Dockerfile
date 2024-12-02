FROM fedora:latest

WORKDIR /app

COPY . .
RUN rm -rf venv build

RUN chmod +x scripts/fedora/install-deps.sh
RUN scripts/fedora/install-deps.sh

RUN chmod +x scripts/fedora/build.sh
RUN chmod +x scripts/fedora/test.sh
CMD ["./scripts/fedora/docker-entrypoint.sh"]
