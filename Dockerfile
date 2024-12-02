FROM fedora:latest

WORKDIR /app

COPY . .
RUN rm -rf venv build

RUN dnf install -y python3 python3-pip python3-virtualenv python3-devel
RUN chmod -R +x scripts
RUN python build.py install-deps

CMD ["python3", "build.py", "docker-entrypoint"]
