FROM python:3


ADD . ./techproguser
WORKDIR ./techproguser


RUN apt-get update
RUN apt-get install -y cmake make python3-pip python-dev build-essential
RUN useradd -ms /bin/bash techproguser
RUN cd /techproguser
RUN mkdir -p build && cd build && cmake .. && make
RUN pip install --upgrade pip
RUN pip install flask argparse

USER techproguser

EXPOSE 5000

CMD ["python", "app.py", "--port", "5000", "--host", "0.0.0.0"]