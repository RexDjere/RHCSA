## RHCSA
This is a Red Hat Certified System Administrator (RHCSA) Study Guide.
________________________________________________________________________________________________________________________________________

About the RHCSA Exam:
- The RHCSA exam is hands on and performance-based (no multiple-choice questions).
- No actual exam material is contained within this guide.
- The RHCSA (EX200) Exam is 2.5 hours long.
- The minimum passing score is 210 out of 300 points (70%).
- The exam consists of about 10 to 15 questions.
- The exam objectives are here: https://www.redhat.com/en/services/training/ex200-red-hat-certified-system-administrator-rhcsa-exam
- More information on the exam can be found here: https://www.redhat.com/en/services/certification/rhcsa
________________________________________________________________________________________________________________________________________

To build this study guide, I am using the following <a href="https://www.fsf.org/about/what-is-free-software" target="_blank">free software</a>:
- Fedora (my GNU/Linux OS of choice): https://getfedora.org/
- Freemind (mind maps): http://freemind.sourceforge.net/wiki/index.php/Main_Page
- Zim Desktop Wiki: http://zim-wiki.org/
- Anki (flashcards): https://apps.ankiweb.net/
	- The Anki flashcard deck is shared here: https://ankiweb.net/shared/info/1904057892
	- See here for important information about how I share the flashcard deck on Anki: 
		[Anki Shared Deck](anki/Anki_Shared_Deck.md)
- git/git-gui (version control): https://git-scm.com/
- KVM (Kernel-based Virtual Machine that I use for hosting guest CentOS VM on Fedora): https://www.linux-kvm.org/page/Main_Page
- CentOS (Community Enterprise Operating System: guest OS for KVM): https://www.centos.org/
________________________________________________________________________________________________________________________________________
To get the most out of this study guide, I recommend the following:
- Have a standalone computer, or virtual machine, with the latest version of CentOS installed to do the exercises (https://www.centos.org/).
- Have a second computer, or a host PC, that meets the requirements below. *You'll install the software listed below on this machine.*
- If you decide to run CentOS in a guest VM:
	- I recommend having at least 2 monitors on the host PC. This makes simultaneously doing the examples and following the study guide easier.
	- I recommend using KVM as your virtualization software.
	- The host PC will need to have a fast CPU, and plenty of RAM (my original setup, an older quad-core AMD CPU with 4 GB of RAM, could not handle it at all).
	- The host PC's OS should allow: 
		- running a guest CentOS VM.
		- installing Freemind, Zim, Anki, and git-gui.
		- I recommend Fedora: https://getfedora.org/ 
- On Fedora 28, you'd install the software with one of these 2 commands: 
	- CASE A: sudo is not enabled for your account: *su -c "dnf install freemind zim anki git-gui"*
	- CASE B: sudo is enabled for your account: *sudo dnf install freemind zim anki git-gui*
- *(optional)* Sign up for a free AnkiWeb account (https://ankiweb.net/)
- Clone https://github.com/RexDjere/RHCSA to this directory on your Linux pc: /home/your_username/Sync/PROJECTS/RHCSA
- After cloning the git repository, RHCSA should have the following files/folders inside:
	- anki (holds exported text file containing all flashcard Q&As)
	- CODE_OF_CONDUCT.md
	- CONTRIBUTING.md
	- cpp_files (c++ files that I created)
	- examples (holds all study guide examples)
	- LICENSE.md (contains GPL v3 license text)
	- lists (holds list text files that I use for examples)
	- MILESTONES.md
	- mindmaps (hold all mindmaps created with Freemind)
	- PULL_REQUEST_TEMPLATE.md
	- README.md (the study guide's home page)
	- zim (holds all zim wiki pages)
	- .git (hidden file)
	- .github (hidden file)
- When you run Zim, you'll want to open the zim folder as a notebook. Once you do, you'll be able to navigate/edit all of the wiki pages.
- Freemind will allow you to open and edit the mindmaps, and Anki will allow you to view/edit the flashcards.
- git/git-gui will allow you to checkout the study guide, edit parts of it if you wish, and create pull requests to update the master branch.
- I'll periodically export the latest version of the Anki flashcards to the anki directory.

Enjoy the definitive RHCSA Study Guide!
	



