[![Gitter](https://badges.gitter.im/plvicente-ringsce/community.svg)](https://gitter.im/plvicente-ringsce/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)


# Morpheus: The Update Engine & Application for RingsCE

**Morpheus** is the official open-source update engine and management application for the [RingsCE](https://ringscejs.gleentech.com) platform — a modern operating system tailored for **Linux ARM64** and **macOS ARM64 (Silicon)** devices.

---

## 🚀 What is Morpheus?

Morpheus is both an **engine** and a **user-facing application** designed to:

- Deliver and apply software updates for RingsCE apps and the system itself.
- Provide a local web-based UI for managing applications, content, and system updates.
- Integrate tightly with `data-dir` to manage ebook libraries, archive content, and runtime metadata.

---

## ✨ Key Features

### ✅ Cross-Platform (ARM64)
- Native support for **Linux ARM64** (e.g., Raspberry Pi, Odroid, Pine64).
- Optimized for **macOS Silicon** (M1/M2/M3).

### 📚 Ebook & Archive Reader
- Parse and manage `.zip`-based ebook bundles located in `data-dir`.
- Seamless JSON/XML metadata support.
- Runtime extraction and manipulation of content without full unpacking.

### 🧠 Update Engine
- Handles application, module, and system updates.
- Works offline and integrates with signed update manifests.
- Minimal dependencies for lightweight environments.

### 🌐 Web UI (localhost)
- Local web interface to:
  - Manage installed apps.
  - Browse and launch content.
  - Check for system and app updates.
  - Control background downloads.
- Runs on `http://localhost:8080` by default.

---

## 🗄️ Database Goals

Morpheus includes an internal metadata and content indexing layer with:

- JSON-first architecture.
- Optional XML support for legacy data formats.
- Scalability through in-memory and local-disk caching for large libraries.
- Extensible backend adapter system for future integration with RingsCE Cloud or offline sync layers.

---

## 🛠️ Building Morpheus

### Requirements
- CMake >= 3.16
- Qt6 (Core, Widgets, Network, Gui)
- GTK (for Linux builds)
- macOS 11.7+ for ARM64 or Linux ARM64 (glibc)

### Build Instructions

```bash
git clone --recurse-submodules https://github.com/ringsce/morpheus.git
cd morpheus
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)

🤝 Contributing

We love contributions! You can:

Submit bug reports or feature requests.
Fork and implement new features (e.g., better archive handling, themes).
Improve localization, documentation, or web UI experience.
📡 Community

💬 Discord: plvicente
🌐 Website: ringscejs.gleentech.com
🧠 Org: github.com/ringsce

![Screenshot](RINGSCE_v2.png)

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](pdvicente@gleentech.com)
